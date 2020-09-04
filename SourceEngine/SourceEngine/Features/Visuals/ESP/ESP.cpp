#include "ESP.h"

#include "../../Aimbot/Aimbot.h"

Color_t OutlineColor = { 0, 0, 0, 180 };
Color_t CondColor = { 254, 202, 87, 255 };
Color_t TargetColor = { 153, 128, 250, 255 };
Color_t InvulnColor = { 59, 59, 152, 255 };
Color_t CloakColor = { 165, 177, 194, 255 };
Color_t FriendColor = { 152, 255, 152, 255 };
Color_t OverhealColor = { 84, 160, 255, 255 };

Color_t HealthColor = { 0, 230, 64, 255 };
Color_t AmmoColor = { 191, 191, 191, 255 };

std::wstring C_ESP::ConvertUtf8ToWide(const std::string& str)
{
	int count = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), NULL, 0);
	std::wstring wstr(count, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), &wstr[0], count);
	return wstr;
}

bool C_ESP::ShouldRun()
{
	if (!bActive)
		return false;

	if (!gInts.Engine->IsInGame() || !gInts.Engine->IsConnected() || gInts.Engine->Con_IsVisible())
		return false;

	if (gInts.EngineVGui->IsGameUIVisible())
		return false;

	return true;
}

bool C_ESP::GetDrawBounds(C_BaseEntity* pEntity, int& x, int& y, int& w, int& h)
{
	if (!gInts.GameMovement || !pEntity)
		return false;

	const matrix3x4& transform = pEntity->GetRgflCoordinateFrame();

	Vec3 mins = pEntity->GetCollideableMins();
	Vec3 maxs = pEntity->GetCollideableMaxs();

	Vec3 points[] = {
		Vec3(mins.x, mins.y, mins.z),
		Vec3(mins.x, maxs.y, mins.z),
		Vec3(maxs.x, maxs.y, mins.z),
		Vec3(maxs.x, mins.y, mins.z),
		Vec3(maxs.x, maxs.y, maxs.z),
		Vec3(mins.x, maxs.y, maxs.z),
		Vec3(mins.x, mins.y, maxs.z),
		Vec3(maxs.x, mins.y, maxs.z)
	};

	Vec3 transformed_points[8];

	for (int i = 0; i < 8; i++)
		Math::VectorTransform(points[i], transform, transformed_points[i]);

	Vec3 flb, brt, blb, frt, frb, brb, blt, flt;

	if (Math::W2S(transformed_points[3], flb) && Math::W2S(transformed_points[5], brt)
		&& Math::W2S(transformed_points[0], blb) && Math::W2S(transformed_points[4], frt)
		&& Math::W2S(transformed_points[2], frb) && Math::W2S(transformed_points[1], brb)
		&& Math::W2S(transformed_points[6], blt) && Math::W2S(transformed_points[7], flt)
		&& Math::W2S(transformed_points[6], blt) && Math::W2S(transformed_points[7], flt))
	{
		Vec3 arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

		float left = flb.x;
		float top = flb.y;
		float righ = flb.x;
		float bottom = flb.y;

		for (int n = 1; n < 8; n++) {
			if (left > arr[n].x)
				left = arr[n].x;

			if (top < arr[n].y)
				top = arr[n].y;

			if (righ < arr[n].x)
				righ = arr[n].x;

			if (bottom > arr[n].y)
				bottom = arr[n].y;
		}

		float x_ = left;
		float y_ = bottom;
		float w_ = (righ - left);
		float h_ = (top - bottom);

		if (pEntity->IsPlayer()) {
			x_ += ((righ - left) / 8.0f);
			w_ -= (((righ - left) / 8.0f) * 2.0f);
		}

		x = static_cast<int>(x_);
		y = static_cast<int>(y_);
		w = static_cast<int>(w_);
		h = static_cast<int>(h_);

		if (x > gScreenSize.w || (x + w) < 0 || y > gScreenSize.h || (y + h) < 0)
			return false;

		return true;
	}

	return false;
}

Color_t C_ESP::GetDrawColor(C_BaseEntity* pLocal, C_BaseEntity* pEntity)
{
	Color_t out = gDraw.GetTeamColor(pEntity->GetTeamNum());

	//instead of the team color let's give it the friend's color, let's keep all the other overrides
	if (pLocal->IsPlayerOnSteamFriendList(pEntity))
		out = FriendColor;

	//target color should override all others
	if (pEntity->GetIndex() == gGlobalInfo.nCurrentTargetIdx)
		out = TargetColor;

	return out;
}

void C_ESP::Paint()
{
	if (auto pLocal{ gEntCache.pLocal })
	{
		if (!ShouldRun())
			return;

		if (bPlayers)
		{
			for (const auto& Player : gEntCache.GetGroup(GroupType_t::PLAYERS_ALL))
			{
				if (Player == pLocal)
					continue;

				if (!Player->IsAlive())
					continue;

				bool bIsFriend = pLocal->IsPlayerOnSteamFriendList(Player);

				switch (nNoTeammatePlayers)
				{
				case 0: { break; }
				case 1: { if (Player->GetTeamNum() == pLocal->GetTeamNum()) { continue; } break; }
				case 2: { if (Player->GetTeamNum() == pLocal->GetTeamNum() && !bIsFriend) { continue; } break; }
				}

				int x = 0, y = 0, w = 0, h = 0;

				if (GetDrawBounds(Player, x, y, w, h))
				{
					Color_t DrawColor = GetDrawColor(pLocal, Player);
					Color_t HealthColor = gDraw.GetHealthColor(Player->GetHealth(), Player->GetMaxHealth());

					int nTextX = ((x + w) + 3);
					int nTextOffset = 0;

					if (bPlayerName)
					{
						PlayerInfo_t PlayerInfo = {};

						if (gInts.Engine->GetPlayerInfo(Player->GetIndex(), &PlayerInfo))
						{
							auto str = ConvertUtf8ToWide(PlayerInfo.name);

							int offset = gDraw.Fonts.at(FONT_ESP_NAME).nTall;
							gDraw.StringCenterW(FONT_ESP_NAME, (x + (w / 2)), (y - offset), DrawColor, str.c_str());
						}
					}

					if (bPlayerHealth)
					{
						gDraw.String(FONT_ESP, nTextX, (y + nTextOffset), HealthColor, "%d/%d", Player->GetHealth(), Player->GetMaxHealth());
						nTextOffset += gDraw.Fonts.at(FONT_ESP).nTall;
					}

					if (bPlayerHealthBar)
					{
						float nHealth = static_cast<float>(Player->GetHealth());
						float nMaxHealth = 100.0f; //Entity's max health
						float overheal = 0.0f;

						if (nHealth > nMaxHealth) {
							overheal = fmod(nHealth, nMaxHealth);
							nHealth = nMaxHealth;
						}

						static const int nWidth = 2;
						int nHeight = (h + (nHealth < nMaxHealth ? 2 : 1));
						int nHeight2 = (h + 1);

						float ratio = (nHealth / nMaxHealth);

						gDraw.Rect(((x - nWidth) - 2), y, nWidth, nHeight2, OutlineColor);
						gDraw.Rect(((x - nWidth) - 2), (y + nHeight - (nHeight * ratio)), nWidth, (nHeight * ratio), HealthColor);

						if (bOutline)
							gDraw.OutlinedRect(((x - nWidth) - 3), (y - 1), (nWidth + 2), (nHeight2 + 2), OutlineColor);

						if (overheal > 0.0f) {
							ratio = (overheal / nMaxHealth);
							gDraw.Rect(((x - nWidth) - 2), (y + (nHeight + 1) - (nHeight * ratio)), nWidth, (nHeight * ratio), OverhealColor);
						}
					}

					if (nPlayerBox)
					{
						if (nPlayerBox == 1)
						{
							int height = (h + 1); //don't ask me /shrug

							gDraw.OutlinedRect(x, y, w, height, DrawColor);
							if (bOutline)
								gDraw.OutlinedRect((x - 1), (y - 1), (w + 2), (height + 2), OutlineColor);
						}

						else if (nPlayerBox == 2)
						{
							gDraw.CornerRect(x, y, w, h, 3, 5, DrawColor);
							if (bOutline)
								gDraw.CornerRect((x - 1), (y - 1), (w + 2), (h + 2), 3, 5, OutlineColor);
						}
					}
				}
			}
		}
	}
}

C_ESP gESP;