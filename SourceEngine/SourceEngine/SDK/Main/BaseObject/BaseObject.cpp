#include "BaseObject.h"

C_BaseEntity *C_BaseObject::GetOwner()
{
	DYNVAR_RETURN(C_BaseEntity *, this, "DT_BaseObject", "m_hBuilder");
}

int C_BaseObject::GetLevel()
{
	DYNVAR_RETURN(int, this, "DT_BaseObject", "m_iUpgradeLevel");
}

bool C_BaseObject::IsSapped()
{
	DYNVAR_RETURN(bool, this, "DT_BaseObject", "m_bHasSapper");
}

bool C_BaseObject::IsPlasmaDisabled()
{
	DYNVAR_RETURN(bool, this, "DT_BaseObject", "m_bPlasmaDisable"); //cowmangler's secondary attack I think
}

bool C_BaseObject::IsDisabled()
{
	DYNVAR_RETURN(bool, this, "DT_BaseObject", "m_bDisabled");
}

int C_BaseObject::GetHealth()
{
	DYNVAR_RETURN(int, this, "DT_BaseObject", "m_iHealth");
}

int C_BaseObject::GetMaxHealth()
{
	DYNVAR_RETURN(int, this, "DT_BaseObject", "m_iMaxHealth");
}

bool C_BaseObject::IsCarried()
{
	DYNVAR_RETURN(int, this, "DT_BaseObject", "m_bCarried");
}