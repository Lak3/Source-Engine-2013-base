#pragma once

#include "../BaseEntity/BaseEntity.h"

class C_BaseCombatWeapon : public C_BaseEntity
{
public:
	int GetWeaponID();
	int GetClip1();
	int GetSlot();
	float GetChargeTime();
	int GetItemDefinitionIndex();
	float GetSwingRange(C_BaseEntity* pLocal);
	bool DoSwingTrace(C_GameTrace& Trace);
	Vec3& GetBulletSpread();
	int GetDamageType();
	bool CanFireCriticalShot(bool bHeadShot = false);
	float GetNextPrimaryAttack();
	float GetNextSecondaryAttack();
	bool CanShoot(C_BaseEntity* pLocal);
	bool CanSecondaryAttack(C_BaseEntity* pLocal);
};