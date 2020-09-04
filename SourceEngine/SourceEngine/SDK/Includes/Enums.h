#pragma once

enum EClientClass
{
    CTestTraceline = 156,
    CTEWorldDecal = 157,
    CTESpriteSpray = 154,
    CTESprite = 153,
    CTESparks = 152,
    CTESmoke = 151,
    CTEShowLine = 149,
    CTEProjectedDecal = 146,
    CTEPlayerDecal = 145,
    CTEPhysicsProp = 142,
    CTEParticleSystem = 141,
    CTEMuzzleFlash = 140,
    CTELargeFunnel = 138,
    CTEKillPlayerAttachments = 137,
    CTEImpact = 136,
    CTEGlowSprite = 135,
    CTEShatterSurface = 148,
    CTEFootprintDecal = 133,
    CTEFizz = 132,
    CTEExplosion = 130,
    CTEEnergySplash = 129,
    CTEEffectDispatch = 128,
    CTEDynamicLight = 127,
    CTEDecal = 125,
    CTEClientProjectile = 124,
    CTEBubbleTrail = 123,
    CTEBubbles = 122,
    CTEBSPDecal = 121,
    CTEBreakModel = 120,
    CTEBloodStream = 119,
    CTEBloodSprite = 118,
    CTEBeamSpline = 117,
    CTEBeamRingPoint = 116,
    CTEBeamRing = 115,
    CTEBeamPoints = 114,
    CTEBeamLaser = 113,
    CTEBeamFollow = 112,
    CTEBeamEnts = 111,
    CTEBeamEntPoint = 110,
    CTEBaseBeam = 109,
    CTEArmorRicochet = 108,
    CTEMetalSparks = 139,
    CSteamJet = 104,
    CSmokeStack = 99,
    DustTrail = 188,
    CFireTrail = 47,
    SporeTrail = 195,
    SporeExplosion = 194,
    RocketTrail = 192,
    SmokeTrail = 193,
    CPropVehicleDriveable = 90,
    ParticleSmokeGrenade = 191,
    CParticleFire = 73,
    MovieExplosion = 189,
    CTEGaussExplosion = 134,
    CEnvQuadraticBeam = 41,
    CEmbers = 34,
    CEnvWind = 45,
    CPrecipitation = 87,
    CBaseTempEntity = 17,
    CWeaponXM1014 = 186,
    CWeaponUSP = 185,
    CWeaponUMP45 = 184,
    CWeaponTMP = 183,
    CSmokeGrenade = 98,
    CWeaponSG552 = 182,
    CWeaponSG550 = 181,
    CWeaponScout = 180,
    CWeaponP90 = 179,
    CWeaponP228 = 178,
    CWeaponMP5Navy = 177,
    CWeaponMAC10 = 176,
    CWeaponM4A1 = 175,
    CWeaponM3 = 174,
    CWeaponM249 = 173,
    CKnife = 70,
    CHEGrenade = 65,
    CWeaponGlock = 172,
    CWeaponGalil = 171,
    CWeaponG3SG1 = 170,
    CFlashbang = 49,
    CWeaponFiveSeven = 169,
    CWeaponFamas = 168,
    CWeaponElite = 167,
    CDEagle = 31,
    CWeaponCSBaseGun = 165,
    CWeaponCSBase = 164,
    CC4 = 23,
    CBaseCSGrenade = 6,
    CWeaponAWP = 163,
    CWeaponAug = 162,
    CAK47 = 1,
    NextBotCombatCharacter = 190,
    CFootstepControl = 51,
    CCSGameRulesProxy = 26,
    CWeaponCubemap = 0,
    CWeaponCycler = 166,
    CTEPlantBomb = 143,
    CTEFireBullets = 131,
    CTERadioIcon = 147,
    CPlantedC4 = 81,
    CCSTeam = 30,
    CCSPlayerResource = 28,
    CCSPlayer = 27,
    CCSRagdoll = 29,
    CTEPlayerAnimEvent = 144,
    CHostage = 66,
    CBaseCSGrenadeProjectile = 7,
    CHandleTest = 64,
    CTeamplayRoundBasedRulesProxy = 107,
    CSpriteTrail = 103,
    CSpriteOriented = 102,
    CSprite = 101,
    CRagdollPropAttached = 93,
    CRagdollProp = 92,
    CPredictedViewModel = 88,
    CPoseController = 86,
    CGameRulesProxy = 63,
    CInfoLadderDismount = 67,
    CFuncLadder = 56,
    CEnvDetailController = 38,
    CWorld = 187,
    CWaterLODControl = 161,
    CWaterBullet = 160,
    CVoteController = 159,
    CVGuiScreen = 158,
    CPropJeep = 89,
    CPropVehicleChoreoGeneric = 0,
    CTest_ProxyToggle_Networkable = 155,
    CTesla = 150,
    CTeamTrainWatcher = 0,
    CBaseTeamObjectiveResource = 16,
    CTeam = 106,
    CSun = 105,
    CParticlePerformanceMonitor = 74,
    CSpotlightEnd = 100,
    CSlideshowDisplay = 97,
    CShadowControl = 96,
    CSceneEntity = 95,
    CRopeKeyframe = 94,
    CRagdollManager = 91,
    CPhysicsPropMultiplayer = 79,
    CPhysBoxMultiplayer = 77,
    CBasePropDoor = 15,
    CDynamicProp = 33,
    CPointCommentaryNode = 85,
    CPointCamera = 84,
    CPlayerResource = 83,
    CPlasma = 82,
    CPhysMagnet = 80,
    CPhysicsProp = 78,
    CPhysBox = 76,
    CParticleSystem = 75,
    CMaterialModifyControl = 72,
    CLightGlow = 71,
    CInfoOverlayAccessor = 69,
    CFuncTrackTrain = 62,
    CFuncSmokeVolume = 61,
    CFuncRotating = 60,
    CFuncReflectiveGlass = 59,
    CFuncOccluder = 58,
    CFuncMonitor = 57,
    CFunc_LOD = 53,
    CTEDust = 126,
    CFunc_Dust = 52,
    CFuncConveyor = 55,
    CBreakableSurface = 22,
    CFuncAreaPortalWindow = 54,
    CFish = 48,
    CEntityFlame = 36,
    CFireSmoke = 46,
    CEnvTonemapController = 44,
    CEnvScreenEffect = 42,
    CEnvScreenOverlay = 43,
    CEnvProjectedTexture = 40,
    CEnvParticleScript = 39,
    CFogController = 50,
    CEntityParticleTrail = 37,
    CEntityDissolve = 35,
    CDynamicLight = 32,
    CColorCorrectionVolume = 25,
    CColorCorrection = 24,
    CBreakableProp = 21,
    CBasePlayer = 13,
    CBaseFlex = 10,
    CBaseEntity = 9,
    CBaseDoor = 8,
    CBaseCombatCharacter = 4,
    CBaseAnimatingOverlay = 3,
    CBoneFollower = 20,
    CBaseAnimating = 2,
    CInfoLightingRelative = 68,
    CAI_BaseNPC = 0,
    CBeam = 19,
    CBaseViewModel = 18,
    CBaseProjectile = 14,
    CBaseParticleEntity = 12,
    CBaseGrenade = 11,
    CBaseCombatWeapon = 5,
};

enum class TraceType_t
{
	TRACE_EVERYTHING,
	TRACE_WORLD_ONLY,
	TRACE_ENTITIES_ONLY,
	TRACE_EVERYTHING_FILTER_PROPS,
};

enum SurfaceFlags_t
{
	DISPSURF_FLAG_SURFACE          = (1 << 0),
	DISPSURF_FLAG_WALKABLE         = (1 << 1),
	DISPSURF_FLAG_BUILDABLE        = (1 << 2),
	DISPSURF_FLAG_SURFPROP1        = (1 << 3),
	DISPSURF_FLAG_SURFPROP2        = (1 << 4),
};

enum class FontDrawType_t
{
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT              = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT           = 2,
};

enum class ClientFrameStage_t
{
	FRAME_UNDEFINED                = -1,
	FRAME_START,

	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,

	FRAME_RENDER_START,
	FRAME_RENDER_END
};

enum StereoEye_t
{
	STEREO_EYE_MONO = 0,
	STEREO_EYE_LEFT = 1,
	STEREO_EYE_RIGHT = 2,
	STEREO_EYE_MAX = 3,
};

enum PlayerControls_t
{
	IN_ATTACK = (1 << 0),
	IN_JUMP = (1 << 1),
	IN_DUCK = (1 << 2),
	IN_FORWARD = (1 << 3),
	IN_BACK = (1 << 4),
	IN_USE = (1 << 5),
	IN_CANCEL = (1 << 6),
	IN_LEFT = (1 << 7),
	IN_RIGHT = (1 << 8),
	IN_MOVELEFT = (1 << 9),
	IN_MOVERIGHT = (1 << 10),
	IN_ATTACK2 = (1 << 11),
	IN_RUN = (1 << 12),
	IN_RELOAD = (1 << 13),
	IN_AL1 = (1 << 14),
	IN_ALT2 = (1 << 15),
	IN_SCORE = (1 << 16),
	IN_SPEED = (1 << 17),
	IN_WALK = (1 << 18),
	IN_ZOOM = (1 << 19),
	IN_WEAPON1 = (1 << 20),
	IN_WEAPON2 = (1 << 21),
	IN_BULLRUSH = (1 << 22),
	IN_GRENADE1 = (1 << 23),
	IN_GRENADE2 = (1 << 24),
	IN_ATTACK3 = (1 << 25),
};

enum class ConVarFlags_t
{
	FCVAR_NONE = 0, // The default, no flags at all

	FCVAR_UNREGISTERED = (1 << 0), // If this is set, don't add to linked list, etc.
	FCVAR_DEVELOPMENT_ONLY = (1 << 1), // Hidden in released products. Flag is removed automatically if ALLOW_DEVELOPMENT_CVARS is defined.
	FCVAR_GAME_DLL = (1 << 2), // defined by the game DLL
	FCVAR_CLIENT_DLL = (1 << 3), // defined by the client DLL
	FCVAR_HIDDEN = (1 << 4), // Hidden. Doesn't appear in find or autocomplete. Like DEVELOPMENTONLY, but can't be compiled out.

	FCVAR_PROTECTED = (1 << 5),  // It's a server cvar, but we don't send the data since it's a password, etc.  Sends 1 if it's not bland/zero, 0 otherwise as value
	FCVAR_SP_ONLY = (1 << 6),  // This cvar cannot be changed by clients connected to a multiplayer server.
	FCVAR_ARCHIVE = (1 << 7),  // set to cause it to be saved to vars.rc
	FCVAR_NOTIFY = (1 << 8),  // notifies players when changed
	FCVAR_USER_INFO = (1 << 9),  // changes the client's info string
	FCVAR_CHEAT = (1 << 14), // Only useable in singleplayer / debug / multiplayer & sv_cheats

	FCVAR_PRINTABLE_ONLY = (1 << 10), // This cvar's string cannot contain unprintable characters ( e.g., used for player name etc ).
	FCVAR_UN_LOGGED = (1 << 11), // If this is a FCVAR_SERVER, don't log changes to the log file / console if we are creating a log
	FCVAR_NEVER_AS_STRING = (1 << 12), // never try to print that cvar

	FCVAR_REPLICATED = (1 << 13), // server setting enforced on clients, TODO rename to FCAR_SERVER at some time
	FCVAR_DEMO = (1 << 16), // record this cvar when starting a demo file
	FCVAR_DONT_RECORD = (1 << 17), // don't record these command in demofiles
	FCVAR_RELOAD_MATERIALS = (1 << 20), // If this cvar changes, it forces a material reload
	FCVAR_RELOAD_TEXTURES = (1 << 21), // If this cvar changes, if forces a texture reload

	FCVAR_NOT_CONNECTED = (1 << 22), // cvar cannot be changed by a client that is connected to a server
	FCVAR_MATERIAL_SYSTEM_THREAD = (1 << 23), // Indicates this cvar is read from the material system thread
	FCVAR_ARCHIVE_XBOX = (1 << 24), // cvar written to config.cfg on the Xbox

	FCVAR_ACCESSIBLE_FROM_THREADS = (1 << 25), // used as a debugging tool necessary to check material system thread convars

	FCVAR_SERVER_CAN_EXECUTE = (1 << 28), // the server is allowed to execute this command on clients via ClientCommand/NET_StringCmd/CBaseClientState::ProcessStringCmd.
	FCVAR_SERVER_CANNOT_QUERY = (1 << 29), // If this is set, then the server is not allowed to query this cvar's value (via IServerPluginHelpers::StartQueryCvarValue).
	FCVAR_CLIENT_CMD_CAN_EXECUTE = (1 << 30), // IVEngineClient::ClientCmd is allowed to execute this command.

	FCVAR_MATERIAL_THREAD_MASK = (FCVAR_RELOAD_MATERIALS | FCVAR_RELOAD_TEXTURES | FCVAR_MATERIAL_SYSTEM_THREAD)
};

enum RenderGroup_t
{
	RENDER_GROUP_OPAQUE_STATIC_HUGE = 0,		// Huge static prop
	RENDER_GROUP_OPAQUE_ENTITY_HUGE = 1,		// Huge opaque entity
	RENDER_GROUP_OPAQUE_STATIC = RENDER_GROUP_OPAQUE_STATIC_HUGE + (4 - 1) * 2, //RENDER_GROUP_CFG_NUM_OPAQUE_ENT_BUCKETS = 4
	RENDER_GROUP_OPAQUE_ENTITY,					// Opaque entity (smallest size, or default)

	RENDER_GROUP_TRANSLUCENT_ENTITY,
	RENDER_GROUP_TWOPASS,						// Implied opaque and translucent in two passes
	RENDER_GROUP_VIEW_MODEL_OPAQUE,				// Solid weapon view models
	RENDER_GROUP_VIEW_MODEL_TRANSLUCENT,		// Transparent overlays etc

	RENDER_GROUP_OPAQUE_BRUSH,					// Brushes

	RENDER_GROUP_OTHER,							// Unclassfied. Won't get drawn.

	// This one's always gotta be last
	RENDER_GROUP_COUNT
};

enum FontFlags_t
{
	FONTFLAG_NONE = 0x000,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400
};

enum VGuiPanel_t
{
	PANEL_ROOT = 0,
	PANEL_GAMEUIDLL,
	PANEL_CLIENTDLL,
	PANEL_TOOLS,
	PANEL_INGAMESCREENS,
	PANEL_GAMEDLL,
	PANEL_CLIENTDLL_TOOLS
};

enum PaintMode_t
{
	PAINT_UIPANELS = (1 << 0),
	PAINT_INGAMEPANELS = (1 << 1),
	PAINT_CURSOR = (1 << 2)
};

enum EObserverModes
{
	OBS_MODE_NONE = 0,		// not in spectator mode
	OBS_MODE_DEATHCAM,		// special mode for death cam animation
	OBS_MODE_FREEZECAM,		// zooms to a target, and freeze-frames on them
	OBS_MODE_FIXED,			// view from a fixed camera position
	OBS_MODE_FIRSTPERSON,	// follow a player in first person view
	OBS_MODE_THIRDPERSON,	// follow a player in third person view
	OBS_MODE_ROAMING,		// free roaming
};