#pragma once
#include "../../SDK/SDK.h"

class C_Movement
{
public:
	bool bBunnyhop = true;

	void DoBunnyhop(C_UserCmd* pCmd);
};

extern C_Movement gMovement;