#include "Hooks.h"

void C_Hooks::Init()
{
	if (gInts.Client)
	{
		using namespace ClientHook;

		Table.Init(gInts.Client);
		Table.Hook(PreEntity::index, &PreEntity::Hook);
		Table.Hook(PostEntity::index, &PostEntity::Hook);
		Table.Hook(ShutDown::index, &ShutDown::Hook);
		Table.Hook(FrameStageNotify::index, &FrameStageNotify::Hook);

		Util::PrintDebug("ClientHook ready.\n");
	}

	if (gInts.ClientMode)
	{
		using namespace ClientModeHook;

		Table.Init(gInts.ClientMode);
		Table.Hook(OverrideView::index, &OverrideView::Hook);
		Table.Hook(ShouldDrawViewModel::index, &ShouldDrawViewModel::Hook);
		Table.Hook(CreateMove::index, &CreateMove::Hook);

		Util::PrintDebug("ClientModeHook ready.\n");
	}

	if (gInts.Prediction)
	{
		using namespace PredictionHook;

		Table.Init(gInts.Prediction);
		Table.Hook(RunCommand::index, &RunCommand::Hook);

		Util::PrintDebug("PredictionHook ready.\n");
	}

	if (gInts.Surface)
	{
		using namespace SurfaceHook;

		Table.Init(gInts.Surface);
		Table.Hook(OnScreenSizeChanged::index, &OnScreenSizeChanged::Hook);
		Table.Hook(LockCursor::index, &LockCursor::Hook);

		Util::PrintDebug("SurfaceHook ready.\n");
	}

	if (gInts.Panel)
	{
		using namespace PanelHook;

		Table.Init(gInts.Panel);
		Table.Hook(PaintTraverse::index, &PaintTraverse::Hook);

		Util::PrintDebug("PaintTraverse ready.\n");
	}

	if (gInts.EngineVGui)
	{
		using namespace EngineVGuiHook;

		Table.Init(gInts.EngineVGui);
		Table.Hook(Paint::index, &Paint::Hook);

		Util::PrintDebug("Paint ready.\n");
	}

	if (gInts.Engine)
	{
		using namespace EngineClientHook;

		Table.Init(gInts.Engine);
		Table.Hook(IsPlayingTimeDemo::index, &IsPlayingTimeDemo::Hook);

		Util::PrintDebug("IsPlayingTimeDemo ready.\n");
	}

	//wndproc
	{
		Util::PrintDebug("Hooking WndProc, did you remember to add valid game name in DLLMain?\n");

		while (!Window)
			Window = FindWindowA(NULL, GAME_NAME);

		WndProcHook::WndProc = (WNDPROC)SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProcHook::Hook);

		Util::PrintDebug("WndProc ready.\n");
	}
}

void C_Hooks::Release()
{
	ClientHook::Table.RestoreTable();
	ClientModeHook::Table.RestoreTable();
	PredictionHook::Table.RestoreTable();
	SurfaceHook::Table.RestoreTable();
	PanelHook::Table.RestoreTable();
	EngineVGuiHook::Table.RestoreTable();
	EngineClientHook::Table.RestoreTable();
	SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProcHook::WndProc);

	Util::PrintDebug("Released all.\n");
}

C_Hooks gHooks;