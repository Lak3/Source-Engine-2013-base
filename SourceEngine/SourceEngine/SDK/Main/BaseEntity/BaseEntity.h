#pragma once
#include "../../NetVars/NetVars.h"

#include "AnimState/TFPlayerAnimState.h" //includes class C_BaseCombatWeapon

class C_BaseEntity
{
public:
	void RemoveEffect(byte Effect);
	void SetFov(int nFov);
	void SetFlags(int nFlags);
	void SetTickBase(int n);
	void SetRenderAngles(const Vec3& v);
	void SetAbsOrigin(const Vec3& v);
	void SetAbsAngles(const Vec3& v);
	void SetCurrentCmd(C_UserCmd* cmd);
	void SetVecOrigin(Vec3& vOrigin);
	void GetRenderBounds(Vec3& vMins, Vec3& vMaxs);
	void UpdateGlowEffect();
	void UpTickBase();
	void UpdateClientSideAnimation();
	void IncreaseTickBase();
	void* GetThrower();
	int DrawModel(int flags);
	int GetClassId();
	int GetMaxHealth();
	int GetHealth();
	int GetTeamNum();
	int GetFlags();
	int GetIndex();
	int GetOwner();
	int GetAmmo();
	int GetHitboxSet();
	int GetTickBase();
	int GetType();
	int GetChockedTicks();
	int GetNumOfHitboxes();
	int GetFov();
	int GetObserverTarget();
	int GetObserverMode();
	float GetSurfaceFriction();
	float GetMaxSpeed();
	float GetWaterJumpTime();
	float GetDamageRadius();
	float flSimulationTime();
	float GetNextAttack();
	float GetStepSize();
	float GetConveyorSpeed();
	const Vec3& GetRenderAngles();
	const Vec3& GetAbsOrigin();
	const Vec3& GetAbsAngles();
	Vec3 GetViewOffset();
	Vec3 GetEyePosition();
	Vec3 GetVecOrigin();
	Vec3 GetWorldSpaceCenter();
	Vec3 GetHitboxPos(int nHitbox);
	Vec3 GetBonePos(int nBone);
	Vec3 GetCollideableMins();
	Vec3 GetCollideableMaxs();
	Vec3 GetVelocity();
	Vec3 GetPunchAngles();
	BYTE GetLifeState();
	C_BaseEntity* FirstMoveChild();
	C_BaseEntity* NextMovePeer();
	C_BaseEntity* GetGroundEntity();
	C_ClientClass* GetClientClass();
	MoveType_t GetMoveType();
	C_BaseCombatWeapon* GetActiveWeapon();
	C_UserCmd* GetCurrentCommand();
	model_t* GetModel();
	matrix3x4& GetRgflCoordinateFrame();
	std::array<float, MAXSTUDIOPOSEPARAM> GetPoseParam();
	bool GetHitboxMinsAndMaxsAndMatrix(int nHitbox, Vec3& mins, Vec3& maxs, matrix3x4& matrix, Vec3* center);
	bool GetHitboxMinsAndMaxs(int nHitbox, Vec3& mins, Vec3& maxs, Vec3* center);
	bool IsPlayerOnSteamFriendList(C_BaseEntity* pEntity);
	bool SetupBones(matrix3x4* pBoneToWorldOut, int nMaxBones, int nBoneMask, float fCurrentTime);
	bool IsBaseCombatWeapon();
	bool IsWearable();
	bool IsInValidTeam();
	bool GetTouched();
	bool IsDormant();
	bool IsOnGround();
	bool IsInWater();
	bool IsAlive();
	bool IsDucking();
	bool IsPlayer();
	const char* GetModelName();
};