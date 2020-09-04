#pragma once
#include "../BaseEntity/BaseEntity.h"

class C_BaseObject : public C_BaseEntity
{
public:
	C_BaseEntity *GetOwner();
	int GetLevel();
	bool IsSapped();
	bool IsPlasmaDisabled();
	bool IsDisabled();
	int GetHealth();
	int GetMaxHealth();
	bool IsCarried();
};