#include "BaseCombatWeapon.h"
#include "../ConVars/ConVars.h"

int C_BaseCombatWeapon::GetWeaponID()
{
	typedef int(__thiscall* FN)(void*);
	return GetVFunc<FN>(this, 377)(this);
}

int C_BaseCombatWeapon::GetClip1()
{
	DYNVAR_RETURN(int, this, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iClip1");
}

int C_BaseCombatWeapon::GetSlot()
{
	typedef int(__thiscall* FN)(PVOID);
	return GetVFunc<FN>(this, 327)(this);
}

float C_BaseCombatWeapon::GetChargeTime()
{
	DYNVAR_RETURN(float, this, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData", "m_flChargeBeginTime");
}

int C_BaseCombatWeapon::GetItemDefinitionIndex()
{
	DYNVAR_RETURN(int, this, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemDefinitionIndex");
}

float C_BaseCombatWeapon::GetSwingRange(C_BaseEntity* pLocal)
{
	typedef int(__thiscall* FN)(C_BaseEntity*);
	return (static_cast<float>(GetVFunc<FN>(this, 451)(pLocal)));
}

bool C_BaseCombatWeapon::DoSwingTrace(C_GameTrace& Trace)
{
	typedef int(__thiscall* FN)(C_GameTrace&);
	return GetVFunc<FN>(this, 453)(Trace);
}

Vec3& C_BaseCombatWeapon::GetBulletSpread()
{
	typedef Vec3& (__thiscall* FN)(PVOID);
	return GetVFunc<FN>(this, 286)(this);
}

int C_BaseCombatWeapon::GetDamageType()
{
	typedef int(__thiscall* FN)(void*);
	return GetVFunc<FN>(this, 378)(this);
}

bool C_BaseCombatWeapon::CanFireCriticalShot(bool bHeadShot)
{
	typedef bool(__thiscall* FN)(void*, bool, C_BaseEntity*);
	return GetVFunc<FN>(this, 421)(this, bHeadShot, nullptr);
}

float C_BaseCombatWeapon::GetNextSecondaryAttack()
{
	DYNVAR_RETURN(float, this, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextSecondaryAttack");
}

float C_BaseCombatWeapon::GetNextPrimaryAttack()
{
	DYNVAR_RETURN(float, this, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextPrimaryAttack");
}

bool C_BaseCombatWeapon::CanShoot(C_BaseEntity* pLocal)
{
	if (auto pNet = gInts.Engine->GetNetChannelInfo())
	{
		float fInterp = gConVars.cl_interp->GetFloat();
		float fLatency = (pNet->GetLatency(FLOW_OUTGOING) + pNet->GetLatency(FLOW_INCOMING));

		return (GetNextPrimaryAttack() < (static_cast<float>(pLocal->GetTickBase() + (fInterp + fLatency)) * gInts.GlobalVars->interval_per_tick));
	}
	
	return false;
}

bool C_BaseCombatWeapon::CanSecondaryAttack(C_BaseEntity* pLocal)
{
	return (GetNextSecondaryAttack() < (static_cast<float>(pLocal->GetTickBase()) * gInts.GlobalVars->interval_per_tick));
}