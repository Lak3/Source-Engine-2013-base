#include "Menu.h"
#include "Input/Input.h"

#include "../Aimbot/Aimbot.h"
#include "../Visuals/ESP/ESP.h"
#include "../Movement/Movement.h"

//TODO: stop using me
namespace InputHelper
{
	enum State_t
	{
		NONE,
		PRESSED,
		HELD
	};

	State_t GetKey(int16_t key)
	{
		static State_t keys[256] = { NONE };

		if (GetKeyState(key) & 0x8000)
		{
			if (keys[key] == PRESSED)
				keys[key] = HELD;

			else if (keys[key] != HELD)
				keys[key] = PRESSED;
		}

		else keys[key] = NONE;

		return keys[key];
	}

	bool IsPressed(int16_t key)
	{
		return (GetKey(key) == PRESSED);
	}

	bool IsHeld(int16_t key)
	{
		return (GetKey(key) == HELD);
	}

	bool IsPressedAndHeld(int16_t key)
	{
		State_t key_state = GetKey(key);

		static std::chrono::time_point<std::chrono::steady_clock> start[256] = { std::chrono::steady_clock::now() };

		if (key_state == PRESSED) {
			start[key] = std::chrono::steady_clock::now();
			return true;
		}

		if (key_state == HELD && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start[key]).count() > 400)
			return true;

		return false;
	}
}

void CMenu::CreateLists()
{
	static bool bDone = false;

	if (!bDone)
	{
		m_ItemLists =
		{
			new CItemList
			{ "ESP",
			{
				new CItemGroup { "Main", {
						new CItemBool("Active",		&gESP.bActive),
						new CItemBool("Outline",	&gESP.bOutline),
						new CItemBool("Class ID's",	&gESP.bDebug)
					}
				},
				
				new CItemGroup { "Players", {
						new CItemBool("Active",			&gESP.bPlayers),
						new CItemInt("No Teammates",	&gESP.nNoTeammatePlayers, { { 0, "Off" }, { 1, "All" }, { 2, "Keep Friends" } }),
						new CItemBool("Name",			&gESP.bPlayerName),
						new CItemBool("Class",			&gESP.bPlayerClass),
						new CItemBool("Health",			&gESP.bPlayerHealth),
						new CItemBool("Cond",			&gESP.bPlayerCond),
						new CItemBool("Health Bar",		&gESP.bPlayerHealthBar),
						new CItemInt("Box",				&gESP.nPlayerBox, { { 0, "Off" }, { 1, "Simple" }, { 2, "Corners" } })
					}
				},
			}
			},

			new CItemList
			{ "Misc",
			{
					new CItemGroup { "Main", {
						new CItemBool("Bunnyhop",			&gMovement.bBunnyhop),
					}
				}
			}
			}
	};

		bDone = true;
	}
}

CMenu::~CMenu()
{
	for (auto ItemList : m_ItemLists)
	{
		for (auto ItemGroup : ItemList->m_ItemGroups)
		{
			for (auto Item : ItemGroup->m_Items)
			{
				delete Item;
			}

			delete ItemGroup;
		}

		delete ItemList;
	}
}

void CMenu::Run()
{
	CreateLists();

	if (InputHelper::IsPressed(VK_INSERT))
	{
		m_Open = !m_Open;
		gInts.Surface->SetCursorAlwaysVisible(m_Open);
	}

	if (m_Open)
	{
		static const Color_t Text			= { 220, 220, 220, 255 };
		static const int ListWidth			= 200;
		static const int ListBarH			= 30;
		static const Color_t ListBG			= { 40, 40, 40, 255 };
		static const Color_t ListBar		= { 30, 30, 30, 255 };
		static const Color_t ListOutline	= { 100, 100, 100, 255 };
		static const int GroupH				= 20;
		static const Color_t GroupBG		= { 35, 35, 35, 255 };
		static const Color_t GroupHover		= { 60, 60, 60, 255 };
		static const Color_t ItemBG			= { 80, 80, 80, 255 };
		static const Color_t ItemHover		= { 225, 177, 44, 255 };

		int x = 0, y = 0;
		gInts.Surface->GetCursorPos(x, y);

		int nHeight = 650;

		for (size_t nItemList = 0; nItemList < m_ItemLists.size(); nItemList++)
		{
			CItemList *ItemList = m_ItemLists.at(nItemList);

			//main background
			gDraw.Rect(ListWidth * nItemList, 0, ListWidth, nHeight, ListBG);
			//bar
			gDraw.Rect(ListWidth * nItemList, 0, ListWidth, ListBarH, ListBar);
			//name
			gDraw.StringCenterV(FONT_MENU, (ListWidth * nItemList) + ListWidth / 2, ListBarH / 2, Text, ItemList->m_Name.c_str());
			//outline
			gDraw.OutlinedRect(ListWidth * nItemList, 0, ListWidth, nHeight, ListOutline);

			int nDrawnItems = 0;

			for (size_t nItemGroup = 0; nItemGroup < ItemList->m_ItemGroups.size(); nItemGroup++)
			{
				CItemGroup *ItemGroup = ItemList->m_ItemGroups.at(nItemGroup);

				int nGroupX = ListWidth * nItemList;
				int nGroupY = ListBarH + (GroupH * nItemGroup) + (nDrawnItems * GroupH);

				bool bHovered = (x > nGroupX && x < (nGroupX + (ListWidth - 2)) && y > nGroupY && y < (nGroupY + GroupH));

				if (bHovered && InputHelper::IsPressed(VK_LBUTTON))
					ItemGroup->m_Open = !ItemGroup->m_Open;

				//main background
				gDraw.Rect(nGroupX + 1, nGroupY, ListWidth - 2, GroupH, bHovered ? GroupHover : GroupBG);
				//name
				gDraw.StringCenterV(FONT_MENU, nGroupX + (ListWidth / 2) + 1, nGroupY + GroupH / 2, Text, ItemGroup->m_Name.c_str());

				if (ItemGroup->m_Open)
				{
					for (size_t nItems = 0; nItems < ItemGroup->m_Items.size(); nItems++)
					{
						CItemBase *Item = ItemGroup->m_Items.at(nItems);

						m_OnAimbotFOV = Item->m_Name == "Aim FOV";

						int nItemY = nGroupY + (GroupH * (nItems + 1));
						bool bHovered = (x > nGroupX && x < (nGroupX + (ListWidth - 2)) && y > nItemY && y < (nItemY + GroupH));

						int nDrawX = (nGroupX + 10);
						int nDrawValX = (nGroupX + 160);
						int nDrawY = (nItemY + (GroupH / 2));
						Color_t DrawCol = (bHovered ? ItemHover : Text);

						switch (Item->e_Type)
						{
							case EItemType::INT:
							{
								CItemInt *Int = reinterpret_cast<CItemInt *>(Item);

								//name
								gDraw.StringCenterVOnly(FONT_MENU, nDrawX, nDrawY, DrawCol, "%s", Int->m_Name.c_str());

								if (!Int->m_Aliases.empty())
								{
									if (bHovered)
									{
										if (InputHelper::IsPressedAndHeld(VK_RBUTTON)) {
											Int->m_AliasIdx++;
											Int->m_AliasIdx = std::clamp(Int->m_AliasIdx, 0, static_cast<int32_t>(Int->m_Aliases.size() - 1));
											*reinterpret_cast<int *>(Int->m_Ptr) = Int->m_Aliases.at(Int->m_AliasIdx).first;
										}

										if (InputHelper::IsPressedAndHeld(VK_LBUTTON)) {
											Int->m_AliasIdx--;
											Int->m_AliasIdx = std::clamp(Int->m_AliasIdx, 0, static_cast<int32_t>(Int->m_Aliases.size() - 1));
											*reinterpret_cast<int *>(Int->m_Ptr) = Int->m_Aliases.at(Int->m_AliasIdx).first;
										}
									}

									//value
									gDraw.StringCenterV(FONT_MENU, nDrawValX, nDrawY, DrawCol, "%s", Int->m_Aliases.at(Int->m_AliasIdx).second.c_str());
								}

								else
								{
									if (bHovered)
									{
										if (InputHelper::IsPressedAndHeld(VK_RBUTTON)) {
											*reinterpret_cast<int *>(Int->m_Ptr) += 1;
											*reinterpret_cast<int *>(Int->m_Ptr) = std::clamp(*reinterpret_cast<int *>(Int->m_Ptr), Int->m_Min, Int->m_Max);
										}

										if (InputHelper::IsPressedAndHeld(VK_LBUTTON)) {
											*reinterpret_cast<int *>(Int->m_Ptr) -= 1;
											*reinterpret_cast<int *>(Int->m_Ptr) = std::clamp(*reinterpret_cast<int *>(Int->m_Ptr), Int->m_Min, Int->m_Max);
										}
									}

									//value
									gDraw.StringCenterV(FONT_MENU, nDrawValX, nDrawY, DrawCol, "%d", *reinterpret_cast<int *>(Int->m_Ptr));
								}

								break;
							}

							case EItemType::FLOAT:
							{
								CItemFloat *Float = reinterpret_cast<CItemFloat *>(Item);

								//name
								gDraw.StringCenterVOnly(FONT_MENU, nDrawX, nDrawY, DrawCol, "%s", Float->m_Name.c_str());

								if (bHovered)
								{
									if (InputHelper::IsPressedAndHeld(VK_RBUTTON)) {
										*reinterpret_cast<float *>(Float->m_Ptr) += Float->m_Step;
										*reinterpret_cast<float *>(Float->m_Ptr) = std::clamp(*reinterpret_cast<float *>(Float->m_Ptr), Float->m_Min, Float->m_Max);
									}

									if (InputHelper::IsPressedAndHeld(VK_LBUTTON)) {
										*reinterpret_cast<float *>(Float->m_Ptr) -= Float->m_Step;
										*reinterpret_cast<float *>(Float->m_Ptr) = std::clamp(*reinterpret_cast<float *>(Float->m_Ptr), Float->m_Min, Float->m_Max);
									}
								}

								//value
								gDraw.StringCenterV(FONT_MENU, nDrawValX, nDrawY, DrawCol, "%.2f", *reinterpret_cast<float *>(Float->m_Ptr));

								break;
							}

							case EItemType::BOOL:
							{
								CItemBool *Bool = reinterpret_cast<CItemBool *>(Item);

								//name
								gDraw.StringCenterVOnly(FONT_MENU, nDrawX, nDrawY, DrawCol, "%s", Bool->m_Name.c_str());

								if (bHovered && InputHelper::IsPressedAndHeld(VK_LBUTTON))
									*Bool->m_Ptr = !*Bool->m_Ptr;

								//value
								gDraw.StringCenterV(FONT_MENU, nDrawValX, nDrawY, DrawCol, "%s", *Bool->m_Ptr ? "On" : "Off");

								break;
							}
						}
					}
				}

				if (ItemGroup->m_Open)
					nDrawnItems += ItemGroup->m_Items.size();
			}
		}
	}

	//gInput.Update();
}

CMenu gMenu;