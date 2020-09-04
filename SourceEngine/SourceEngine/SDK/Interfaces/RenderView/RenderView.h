#pragma once

class C_RenderView
{
public:
	void GetMatricesForView(const C_ViewSetup& view, VMatrix* pWorldToView, VMatrix* pViewToProjection, VMatrix* pWorldToProjection, VMatrix* pWorldToPixels) {
		typedef void(__thiscall* FN)(PVOID, const C_ViewSetup&, VMatrix*, VMatrix*, VMatrix*, VMatrix*);
		GetVFunc<FN>(this, 50)(this, view, pWorldToView, pViewToProjection, pWorldToProjection, pWorldToPixels);
	}
};

#define VENGINE_RENDERVIEW_INTERFACE_VERSION "VEngineRenderView014"