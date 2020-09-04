#include "EngineClientHook.h"

bool __stdcall EngineClientHook::IsPlayingTimeDemo::Hook()
{
	// ...

	return Table.Original<fn>(index)(gInts.Engine);
}

VMT::Table EngineClientHook::Table;