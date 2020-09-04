#pragma once

//Main hash function
//And prehashed strings allowing for fast comparisong.
namespace Hash
{
	int String(const char* szOrg);

	//Panels
	constexpr int HudScope = 200208064;
	constexpr int FocusOverlayPanel = -861513321;
}