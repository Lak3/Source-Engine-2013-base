#pragma once
#include "../../Utils/Utils.h"

#include "Enums.h"
#include "Structs.h"

#include "dt_common.h"
#include "dt_recv.h"

class VMatrix {
private:
	Vec3 m[4][4];

public:
	const matrix3x4& As3x4() const {
		return *((const matrix3x4*)this);
	}
};

class C_ViewSetup
{
public:
	// left side of view window
	int			x;
	int			m_nUnscaledX;
	// top side of view window
	int			y;
	int			m_nUnscaledY;
	// width of view window
	int			width;
	int			m_nUnscaledWidth;
	// height of view window
	int			height;
	// which eye are we rendering?
	StereoEye_t m_eStereoEye;
	int			m_nUnscaledHeight;

	// the rest are only used by 3D views

		// Orthographic projection?
	bool		m_bOrtho;
	// View-space rectangle for ortho projection.
	float		m_OrthoLeft;
	float		m_OrthoTop;
	float		m_OrthoRight;
	float		m_OrthoBottom;

	// horizontal FOV in degrees
	float		fov;
	// horizontal FOV in degrees for in-view model
	float		fovViewmodel;

	// 3D origin of camera
	Vec3		origin;

	// heading of camera (pitch, yaw, roll)
	Vec3		angles;
	// local Z coordinate of near plane of camera
	float		zNear;
	// local Z coordinate of far plane of camera
	float		zFar;

	// local Z coordinate of near plane of camera ( when rendering view model )
	float		zNearViewmodel;
	// local Z coordinate of far plane of camera ( when rendering view model )
	float		zFarViewmodel;

	// set to true if this is to draw into a subrect of the larger screen
	// this really is a hack, but no more than the rest of the way this class is used
	bool		m_bRenderToSubrectOfLargerScreen;

	// The aspect ratio to use for computing the perspective projection matrix
	// (0.0f means use the viewport)
	float		m_flAspectRatio;

	// Controls for off-center projection (needed for poster rendering)
	bool		m_bOffCenter;
	float		m_flOffCenterTop;
	float		m_flOffCenterBottom;
	float		m_flOffCenterLeft;
	float		m_flOffCenterRight;

	// Control that the SFM needs to tell the engine not to do certain post-processing steps
	bool		m_bDoBloomAndToneMapping;

	// Cached mode for certain full-scene per-frame varying state such as sun entity coverage
	bool		m_bCacheFullSceneState;

	// If using VR, the headset calibration will feed you a projection matrix per-eye.
	// This does NOT override the Z range - that will be set up as normal (i.e. the values in this matrix will be ignored).
	bool        m_bViewToProjectionOverride;
	VMatrix     m_ViewToProjection;
};

class C_MoveData
{
public:
	bool m_bFirstRunOfFunctions : 1;
	bool m_bGameCodeMovedPlayer : 1;

	void* m_nPlayerHandle; // edict index on server, client entity handle on client

	int    m_nImpulseCommand; // Impulse command issued.
	Vec3 m_vecViewAngles; // Command view angles (local space)
	Vec3 m_vecAbsViewAngles; // Command view angles (world space)
	int    m_nButtons; // Attack buttons.
	int    m_nOldButtons; // From host_client->oldbuttons;
	float  m_flForwardMove;
	float  m_flSideMove;
	float  m_flUpMove;

	float m_flMaxSpeed;
	float m_flClientMaxSpeed;

	// Variables from the player edict (sv_player) or entvars on the client.
	// These are copied in here before calling and copied out after calling.
	Vec3 m_vecVelocity; // edict::velocity		// Current movement direction.
	Vec3 m_vecAngles; // edict::angles
	Vec3 m_vecOldAngles;

	// Output only
	float  m_outStepHeight; // how much you climbed this move
	Vec3 m_outWishVel; // This is where you tried
	Vec3 m_outJumpVel; // This is your jump velocity

					   // Movement constraints	(radius 0 means no constraint)
	Vec3 m_vecConstraintCenter;
	float  m_flConstraintRadius;
	float  m_flConstraintWidth;
	float  m_flConstraintSpeedFactor;

	void        SetAbsOrigin(const Vec3& vec);
	const Vec3& GetAbsOrigin() const;

	// private:
	Vec3 m_vecAbsOrigin; // edict::origin
};

class CEntityGroundContact
{
public:
	int		entindex;
	float	minheight;
	float	maxheight;
};

class C_UserCmd
{
public:
	virtual ~C_UserCmd() {};

	// For matching server and client commands for debugging
	int		command_number;

	// the tick the client created this command
	int		tick_count;

	// Player instantaneous view angles.
	Vec3	viewangles;
	// Intended velocities
	//	forward velocity.
	float	forwardmove;
	//  sideways velocity.
	float	sidemove;
	//  upward velocity.
	float	upmove;
	// Attack button states
	int		buttons;
	// Impulse command issued.
	byte    impulse;
	// Current weapon id
	int		weaponselect;
	int		weaponsubtype;

	int		random_seed;	// For shared random functions

	//int		server_random_seed; // Only the server populates this seed

	short	mousedx;		// mouse accum in x from create move
	short	mousedy;		// mouse accum in y from create move

	// Client only, tracks whether we've predicted this command at least once
	bool	hasbeenpredicted;
};

class C_ClientClass
{
public:
	BYTE Pad[8];
	char* szNetworkName;
	RecvTable* pRecvTable;
	C_ClientClass* pNextClass;
	int iClassID;
};

class C_BaseEntity; //forward declare

class C_TraceFilter
{
public:
	virtual bool ShouldHitEntity(void* entity, int contents_mask) = 0;
	virtual TraceType_t GetTraceType() const = 0;
};

class C_BaseTrace
{
public:
	bool IsDispSurface(void) { return ((DispFlags & SurfaceFlags_t::DISPSURF_FLAG_SURFACE) != 0); }
	bool IsDispSurfaceWalkable(void) { return ((DispFlags & SurfaceFlags_t::DISPSURF_FLAG_WALKABLE) != 0); }
	bool IsDispSurfaceBuildable(void) { return ((DispFlags & SurfaceFlags_t::DISPSURF_FLAG_BUILDABLE) != 0); }
	bool IsDispSurfaceSurfProp1(void) { return ((DispFlags & SurfaceFlags_t::DISPSURF_FLAG_SURFPROP1) != 0); }
	bool IsDispSurfaceSurfProp2(void) { return ((DispFlags & SurfaceFlags_t::DISPSURF_FLAG_SURFPROP2) != 0); }

public:
	Vec3			vStartPos = Vec3();
	Vec3			vEndPos = Vec3();
	cplane_t		Plane = {};
	float			flFraction = 0.0f;
	int				iContents = 0;
	unsigned short	DispFlags = 0;
	bool			bAllSolid = false;
	bool			bStartSolid = false;

	C_BaseTrace()
	{

	}

private:
	C_BaseTrace(const C_BaseTrace& othr);
};

class C_GameTrace : public C_BaseTrace
{
public:
	bool DidHitWorld() const;
	bool DidHitNonWorldEntity() const;
	int  GetEntityIndex() const;

	bool DidHit() const {
		return (flFraction < 1 || bAllSolid || bStartSolid);
	}

public:
	float			fraction_left_solid;
	csurface_t		surface;
	int				hit_group;
	short			physics_bone;
	C_BaseEntity* entity;
	int				hitbox;

	C_GameTrace() { }
	C_GameTrace(const C_GameTrace& othr);
};