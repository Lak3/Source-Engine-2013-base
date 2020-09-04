#include "PanelHook.h"

void __stdcall PanelHook::PaintTraverse::Hook(unsigned int vgui_panel, bool force_repaint, bool allow_force)
{
	Table.Original<fn>(index)(gInts.Panel, vgui_panel, force_repaint, allow_force);

	//...
}

VMT::Table PanelHook::Table;