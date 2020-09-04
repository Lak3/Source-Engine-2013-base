#pragma once

#include "../BaseEntity/BaseEntity.h"

struct ConVars_t
{
	ConVar *cl_interp		= nullptr;
	ConVar *cl_interp_ratio	= nullptr;
	ConVar *cl_updaterate	= nullptr;

	ConVar *sv_gravity = nullptr;
	ConVar *cl_flipviewmodels = nullptr;

	void Init();
};

extern ConVars_t gConVars;