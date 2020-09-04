#include "ClientModeHook.h"

#include "../../Features/Aimbot/Aimbot.h"
#include "../../Features/Prediction/Prediction.h"
#include "../../Features/Movement/Movement.h"

void __stdcall ClientModeHook::OverrideView::Hook(C_ViewSetup *pView)
{
	Table.Original<fn>(index)(gInts.ClientMode, pView);

	pView->fov = 120.0f;
}

bool __stdcall ClientModeHook::ShouldDrawViewModel::Hook()
{
	return Table.Original<fn>(index)(gInts.ClientMode);

	//...
}

bool __stdcall ClientModeHook::CreateMove::Hook(float input_sample_frametime, C_UserCmd* pCmd)
{
	if (!pCmd || !pCmd->command_number)
		return false;

	uintptr_t _bp; __asm mov _bp, ebp;
	bool* pSendPacket = (bool*)(***(uintptr_t***)_bp - 0x1);

	//"Cache" this ticks weaponinfo
	{
		auto pLocal = gEntCache.pLocal;
		auto pLocalWeapon = gEntCache.pLocalWeapon;

		if (pLocal && pLocalWeapon)
		{
			gGlobalInfo.bWeaponCanShoot = pLocalWeapon->CanShoot(pLocal);
		}
	}

	Vec3  vOldAngles = pCmd->viewangles;
	float flOldSideMove = pCmd->sidemove;
	float flOldForwardMove = pCmd->forwardmove;

	gMovement.DoBunnyhop(pCmd);

	//gPrediction.Start(pCmd);
	{
		// ...
	}
	//gPrediction.End(pCmd);

	return Table.Original<fn>(index)(gInts.ClientMode, input_sample_frametime, pCmd);
}

VMT::Table ClientModeHook::Table;