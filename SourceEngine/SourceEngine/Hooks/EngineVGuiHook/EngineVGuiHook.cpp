#include "EngineVGuiHook.h"

#include "../../Features/Visuals/ESP/ESP.h"
#include "../../Features/Visuals/Radar/Radar.h"
#include "../../Features/Menu/Menu.h"

void __stdcall EngineVGuiHook::Paint::Hook(int mode)
{
	if (!gScreenSize.w || !gScreenSize.h) {
		gScreenSize.Update();
		return;
	}

	static auto StartDrawing = reinterpret_cast<void(__thiscall *)(void *)>(gPattern.Find("vguimatsurface.dll", "55 8B EC 64 A1 ? ? ? ? 6A FF 68 ? ? ? ? 50 64 89 25 ? ? ? ? 83 EC 14"));
	static auto FinishDrawing = reinterpret_cast<void(__thiscall *)(void *)>(gPattern.Find("vguimatsurface.dll", "55 8B EC 6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 51 56 6A 00"));

	//HACK: for some reason we need to do this
	{
		static bool bInitIcons = false;

		if (!bInitIcons)
		{
			for (int n = 0; n < 10; n++)
				gDraw.Icon(-200, 0, 18, 18, n);

			bInitIcons = true;
		}
	}

	Table.Original<fn>(index)(gInts.EngineVGui, mode);

	if (mode & PAINT_UIPANELS)
	{
		//let's update WorldToProjection VMatrix here
		{
			C_ViewSetup ViewSetup = {};

			if (gInts.Client->GetPlayerView(ViewSetup))
			{
				VMatrix WorldToView = {}, ViewToProjection = {}, WorldToPixels = {};
				gInts.RenderView->GetMatricesForView(ViewSetup, &WorldToView, &ViewToProjection, &gGlobalInfo.WorldToProjection, &WorldToPixels);
			}
		}

		StartDrawing(gInts.Surface);
		{
			gESP.Paint();
			gMenu.Run();
		}
		FinishDrawing(gInts.Surface);
	}
}

VMT::Table EngineVGuiHook::Table;

void IllSaveThisHere() {
	static Color_t color = { 225, 177, 44, 255 };

	if (gEntCache.pLocal)
	{
		auto PLAYERS_ALL = gEntCache.GetGroup(GroupType_t::PLAYERS_ALL);
		auto PLAYERS_ENEMIES = gEntCache.GetGroup(GroupType_t::PLAYERS_ENEMIES);
		auto PLAYERS_TEAMMATES = gEntCache.GetGroup(GroupType_t::PLAYERS_TEAMMATES);

		gDraw.String(FONT_DEBUG, 300, 200, color, "PLAYERS_ALL: %d", PLAYERS_ALL.size());
		gDraw.String(FONT_DEBUG, 300, 220, color, "PLAYERS_ENEMIES: %d", PLAYERS_ENEMIES.size());
		gDraw.String(FONT_DEBUG, 300, 240, color, "PLAYERS_TEAMMATES: %d", PLAYERS_TEAMMATES.size());

		static const wchar_t* text = L"penis";
		static int x = 0, y = 0, text_w = 0, text_h = 0;

		if (!text_w || !text_h)
			gInts.Surface->GetTextSize(gDraw.Fonts.at(FONT_DEBUG).dwFont, text, text_w, text_h);

		x = ((gScreenSize.w / 2) - (text_w / 2)) + (cos(gInts.GlobalVars->curtime) * 150.0f);
		y = ((gScreenSize.h / 2) - (text_h / 2)) + (sin(gInts.GlobalVars->curtime) * 150.0f);

		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x), static_cast<int>(y), { 255, 255, 255, 255 });
		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x + text_w), static_cast<int>(y), { 255, 255, 255, 255 });
		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x), static_cast<int>(y + text_h), { 255, 255, 255, 255 });
		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x + text_w), static_cast<int>(y + text_h), { 255, 255, 255, 255 });
		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x + (text_w / 2)), static_cast<int>(y), { 255, 255, 255, 255 });
		gDraw.Line((gScreenSize.w / 2), (gScreenSize.h / 2), static_cast<int>(x + (text_w / 2)), static_cast<int>(y + text_h), { 255, 255, 255, 255 });

		gDraw.Rect(static_cast<int>(x), static_cast<int>(y), text_w, text_h, { 20, 20, 20, 255 });
		gDraw.OutlinedRect(static_cast<int>(x - 1), static_cast<int>(y - 1), (text_w + 2), (text_h + 2), { 255, 255, 255, 255 });

		gDraw.String(FONT_DEBUG, static_cast<int>(x), static_cast<int>(y), { 255, 255, 255, 255 }, "penis");

		for (const auto& Player : PLAYERS_ENEMIES)
		{
			if (!Player->IsAlive())
				continue;

			Vec3 vecOrigin = Player->GetVecOrigin();
			Vec3 vecScreen = Vec3();

			if (Math::W2S(vecOrigin, vecScreen))
				gDraw.String(FONT_ESP, static_cast<int>(vecScreen.x), static_cast<int>(vecScreen.y), color, "enemy player");
		}
	}
}