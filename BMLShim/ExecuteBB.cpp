#include "ExecuteBB.h"
#include "ScriptHelper.h"
#include "RegisterBB.h"

using namespace ScriptHelper;

namespace ExecuteBB {
	void InitFont(FontType type, int fontIndex) {
	}
	int GetFont(FontType type) {
		return 0;
	}
	FontType GetFontType(int font) {
		return NOFONT;
	}

	template<typename T>
	CKParameter* CreateParamValue(CKGUID guid, CKSTRING name, T value) {
		return nullptr;

	}

	CKParameter* CreateParamObject(CKGUID guid, CKSTRING name, CKObject* value) {
		return nullptr;

	}

	CKParameter* CreateParamString(CKSTRING name, CKSTRING value) {
		return nullptr;

	}

	CKBehavior* Create2DText(CK2dEntity* target, FontType font, CKSTRING text, int align, VxRect margin, Vx2DVector offset,
		Vx2DVector pindent, CKMaterial* bgmat, float caretsize, CKMaterial* caretmat, int flags) {
		return nullptr;

	}

	CKBehavior* CreatePhysicalize(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter) {
		return nullptr;

	}

	CKBehavior* CreatePhysicalizeConvex(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, CKMesh* mesh) {
		return nullptr;

	}

	CKBehavior* CreatePhysicalizeBall(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, VxVector ballCenter, float ballRadius) {
		return nullptr;

	}

	CKBehavior* CreatePhysicalizeConcave(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, CKMesh* mesh) {
		return nullptr;

	}

	void PhysicalizeParam(CKBehavior* beh, CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter) {
	}

	void PhysicalizeConvex(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, CKMesh* mesh) {
	}

	void PhysicalizeBall(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, VxVector ballCenter, float ballRadius) {
	}

	void PhysicalizeConcave(CK3dEntity* target, CKBOOL fixed, float friction, float elasticity, float mass,
		CKSTRING collGroup, CKBOOL startFrozen, CKBOOL enableColl, CKBOOL calcMassCenter, float linearDamp,
		float rotDamp, CKSTRING collSurface, VxVector massCenter, CKMesh* mesh) {
	}

	void Unphysicalize(CK3dEntity* target) {
	}

	CKBehavior* CreateSetPhysicsForce(CK3dEntity* target, VxVector position, CK3dEntity* posRef, VxVector direction, CK3dEntity* directionRef, float force) {
		return nullptr;

	}

	void SetPhysicsForce(CK3dEntity* target, VxVector position, CK3dEntity* posRef, VxVector direction, CK3dEntity* directionRef, float force) {
	}

	void UnsetPhysicsForce(CK3dEntity* target) {
	}

	CKBehavior* CreatePhysicsWakeUp(CK3dEntity* target) {
		return nullptr;
	}

	void PhysicsWakeUp(CK3dEntity* target) {
	}

	CKBehavior* CreateObjectLoad(CKSTRING file, CKSTRING mastername, CK_CLASSID filter, CKBOOL addToScene,
		CKBOOL reuseMesh, CKBOOL reuseMtl, CKBOOL dynamic) {
		return nullptr;
	}

	std::pair<XObjectArray*, CKObject*> ObjectLoad(CKSTRING file, bool rename, CKSTRING mastername, CK_CLASSID filter,
		CKBOOL addToScene, CKBOOL reuseMesh, CKBOOL reuseMtl, CKBOOL dynamic) {
		return { nullptr, nullptr };
	}

	CKBehavior* CreatePhysicsImpulse(CK3dEntity* target, VxVector position, CK3dEntity* posRef, VxVector direction,
		CK3dEntity* dirRef, float impulse) {
		return nullptr;
	}

	void PhysicsImpulse(CK3dEntity* target, VxVector position, CK3dEntity* posRef, VxVector direction,
		CK3dEntity* dirRef, float impulse) {
		
	}

	void Init(CKContext* context) {
		
	}
}