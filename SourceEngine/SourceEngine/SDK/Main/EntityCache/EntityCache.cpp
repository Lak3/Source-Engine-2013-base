#include "EntityCache.h"

void C_EntityCache::Fill()
{
	C_BaseEntity *_pLocal = gInts.EntityList->GetClientEntity(gInts.Engine->GetLocalPlayer());

	if (_pLocal && _pLocal->IsInValidTeam())
	{
		pLocal = _pLocal;
		pLocalWeapon = pLocal->GetActiveWeapon();

		for (int n = 1; n < gInts.EntityList->GetHighestEntityIndex(); n++)
		{
			C_BaseEntity *pEntity = gInts.EntityList->GetClientEntity(n);

			if (!pEntity || pEntity->IsDormant())
				continue;

			switch (pEntity->GetClassId())
			{
				case CCSPlayer:
				{
					Groups[GroupType_t::PLAYERS_ALL].push_back(pEntity);
					Groups[pEntity->GetTeamNum() != pLocal->GetTeamNum() ? GroupType_t::PLAYERS_ENEMIES : GroupType_t::PLAYERS_TEAMMATES].push_back(pEntity);
					break;
				}
				
				default: break;
			}
		}
	}
}

void C_EntityCache::Clear()
{
	pLocal = nullptr;
	pLocalWeapon = nullptr;

	for (auto &group : Groups)
		group.second.clear();
}

const std::vector<C_BaseEntity *> &C_EntityCache::GetGroup(const GroupType_t &group)
{
	return Groups[group];
}

C_EntityCache gEntCache;