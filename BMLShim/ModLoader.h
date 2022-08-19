#pragma once
#include "IBML.h"
class ModLoader: public IBML
{
	CKContext* GetCKContext() override;
	CKRenderContext* GetRenderContext() override;

	void ExitGame() override;

	CKAttributeManager* GetAttributeManager() override;
	CKBehaviorManager* GetBehaviorManager() override;
	CKCollisionManager* GetCollisionManager() override;
	InputHook* GetInputManager() override;
	CKMessageManager* GetMessageManager() override;
	CKPathManager* GetPathManager() override;
	CKParameterManager* GetParameterManager() override;
	CKRenderManager* GetRenderManager() override;
	CKSoundManager* GetSoundManager() override;
	CKTimeManager* GetTimeManager() override;

	void AddTimer(CKDWORD delay, std::function<void()> callback) override;
	void AddTimerLoop(CKDWORD delay, std::function<bool()> callback) override;
	void AddTimer(float delay, std::function<void()> callback) override;
	void AddTimerLoop(float delay, std::function<bool()> callback) override;

	bool IsCheatEnabled() override;
	void EnableCheat(bool enable) override;

	void SendIngameMessage(CKSTRING msg) override;

	void RegisterCommand(ICommand* cmd) override;

	void SetIC(CKBeObject* obj, bool hierarchy = false) override;
	void RestoreIC(CKBeObject* obj, bool hierarchy = false) override;
	void Show(CKBeObject* obj, CK_OBJECT_SHOWOPTION show, bool hierarchy = false) override;

	bool IsIngame() override;
	bool IsPaused() override;
	bool IsPlaying() override;

	CKDataArray* GetArrayByName(CKSTRING name) override;
	CKGroup* GetGroupByName(CKSTRING name) override;
	CKMaterial* GetMaterialByName(CKSTRING name) override;
	CKMesh* GetMeshByName(CKSTRING name) override;
	CK2dEntity* Get2dEntityByName(CKSTRING name) override;
	CK3dEntity* Get3dEntityByName(CKSTRING name) override;
	CK3dObject* Get3dObjectByName(CKSTRING name) override;
	CKCamera* GetCameraByName(CKSTRING name) override;
	CKTargetCamera* GetTargetCameraByName(CKSTRING name) override;
	CKLight* GetLightByName(CKSTRING name) override;
	CKTargetLight* GetTargetLightByName(CKSTRING name) override;
	CKSound* GetSoundByName(CKSTRING name) override;
	CKTexture* GetTextureByName(CKSTRING name) override;
	CKBehavior* GetScriptByName(CKSTRING name) override;

	void RegisterBallType(CKSTRING ballFile, CKSTRING ballId, CKSTRING ballName, CKSTRING objName, float friction, float elasticity,
	                      float mass, CKSTRING collGroup, float linearDamp, float rotDamp, float force, float radius) override;
	void RegisterFloorType(CKSTRING floorName, float friction, float elasticity, float mass, CKSTRING collGroup, bool enableColl) override;
	void RegisterModulBall(CKSTRING modulName, bool fixed, float friction, float elasticity, float mass, CKSTRING collGroup,
	                       bool frozen, bool enableColl, bool calcMassCenter, float linearDamp, float rotDamp, float radius) override;
	void RegisterModulConvex(CKSTRING modulName, bool fixed, float friction, float elasticity, float mass, CKSTRING collGroup,
	                         bool frozen, bool enableColl, bool calcMassCenter, float linearDamp, float rotDamp) override;
	void RegisterTrafo(CKSTRING modulName) override;
	void RegisterModul(CKSTRING modulName) override;

	int GetModCount() override;
	class IMod* GetMod(int index) override;

	float GetSRScore() override;
	int GetHSScore() override;

	void SkipRenderForNextTick() override;
};

