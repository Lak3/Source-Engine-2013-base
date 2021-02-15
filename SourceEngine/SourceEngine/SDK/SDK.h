#pragma once

#include "Main/BaseEntity/BaseEntity.h"
#include "Main/BaseCombatWeapon/BaseCombatWeapon.h"
#include "Main/BaseObject/BaseObject.h"

#include "Main/DrawUtils/DrawUtils.h"
#include "Main/EntityCache/EntityCache.h"
#include "Main/VisCheck/VisCheck.h"
#include "Main/GlobalInfo/GlobalInfo.h"
#include "Main/ConVars/ConVars.h"

#pragma warning( disable : 4996 )

#define TIME_TO_TICKS( dt )	( (int)( 0.5f + (float)(dt) / gInts.GlobalVars->interval_per_tick ) )
#define TICKS_TO_TIME( t )	( gInts.GlobalVars->interval_per_tick * ( t ) )
#define TICK_INTERVAL		( gInts.GlobalVars->interval_per_tick )

namespace Util
{
	inline void TraceHull(const Vec3& vecStart, const Vec3& vecEnd, const Vec3& vecHullMin, const Vec3& vecHullMax,
		unsigned int nMask, C_TraceFilter* pFilter, C_GameTrace* pTrace)
	{
		Ray_t ray;
		ray.Init(vecStart, vecEnd, vecHullMin, vecHullMax);
		gInts.EngineTrace->TraceRay(ray, nMask, pFilter, pTrace);
	}

	inline void InitDebug() {
#ifdef _DEBUG
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
#endif
	}

	inline void ReleaseDebug() {
#ifdef _DEBUG
		FreeConsole();
		system("exit");
#endif
	}

	inline void PrintDebug(const char* szString) {
#ifdef _DEBUG
		printf(szString);
#endif
	}
}