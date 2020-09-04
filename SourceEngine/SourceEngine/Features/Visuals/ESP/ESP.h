#pragma once

#include "../../../SDK/SDK.h"

class C_ESP
{
public:
	bool bActive = true;
	bool bOutline = false;

	bool bPlayers = true;
	int nNoTeammatePlayers = 2; //0 off 1 all 2 keep friends
	bool bPlayerName = true;
	bool bPlayerClass = true;
	bool bPlayerHealth = false;
	bool bPlayerCond = true;
	bool bPlayerHealthBar = true;
	int nPlayerBox = 2; //0 off 1 simple 2 corners

	bool bDebug = false;

private:
	std::wstring ConvertUtf8ToWide(const std::string& str);

private:
	bool ShouldRun();
	bool GetDrawBounds(C_BaseEntity* pEntity, int& x, int& y, int& w, int& h);
	Color_t GetDrawColor(C_BaseEntity* pLocal, C_BaseEntity* pEntity);

public:
	void Paint();
};

extern C_ESP gESP;