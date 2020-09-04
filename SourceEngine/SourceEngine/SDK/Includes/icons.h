#pragma once
#include <string>

enum ETextureID
{
	DEFAULT_CT,
	DEFAULT_T,
	DEFUSER
};

namespace ICONS {

	inline const int WIDTH = 64;
	inline const int HEIGHT = 64;

	inline int ID[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	//All non "CSS" are leftovers from Team Fortress 2
	inline std::string TEXTURES[10] = {
		"vgui/gfx/vgui/defuser.vtf", //CSS
		"hud/leaderboard_class_soldier.vtf",
		"vgui/avatar_default-t_64.vtf", //CSS
		"vgui/avatar_default_64.vtf", //CSS
		"hud/leaderboard_class_demo.vtf",
		"hud/leaderboard_class_medic.vtf",
		"hud/leaderboard_class_heavy.vtf",
		"hud/leaderboard_class_pyro.vtf",
		"hud/leaderboard_class_spy.vtf",
		"hud/leaderboard_class_engineer.vtf"
	};
}