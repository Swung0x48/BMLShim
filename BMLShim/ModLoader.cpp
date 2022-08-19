#include "ModLoader.h"

CKContext* ModLoader::GetCKContext()
{
    return nullptr;
}

CKRenderContext* ModLoader::GetRenderContext()
{
    return nullptr;
}

void ModLoader::ExitGame()
{
}

CKAttributeManager* ModLoader::GetAttributeManager()
{
	return nullptr;
}

CKBehaviorManager* ModLoader::GetBehaviorManager()
{
	return nullptr;
}

CKCollisionManager* ModLoader::GetCollisionManager()
{
	return nullptr;
}

InputHook* ModLoader::GetInputManager()
{
	return nullptr;
}

CKMessageManager* ModLoader::GetMessageManager()
{
	return nullptr;

}

CKPathManager* ModLoader::GetPathManager()
{
	return nullptr;

}

CKParameterManager* ModLoader::GetParameterManager()
{
	return nullptr;

}

CKRenderManager* ModLoader::GetRenderManager()
{
	return nullptr;

}

CKSoundManager* ModLoader::GetSoundManager()
{
	return nullptr;

}

CKTimeManager* ModLoader::GetTimeManager()
{
	return nullptr;

}

void ModLoader::AddTimer(CKDWORD delay, std::function<void()> callback)
{
}

void ModLoader::AddTimerLoop(CKDWORD delay, std::function<bool()> callback)
{
}

void ModLoader::AddTimer(float delay, std::function<void()> callback)
{
}

void ModLoader::AddTimerLoop(float delay, std::function<bool()> callback)
{
}

bool ModLoader::IsCheatEnabled()
{
	return false;
}

void ModLoader::EnableCheat(bool enable)
{
}

void ModLoader::SendIngameMessage(CKSTRING msg)
{
}

void ModLoader::RegisterCommand(ICommand* cmd)
{
}

void ModLoader::SetIC(CKBeObject* obj, bool hierarchy)
{
}

void ModLoader::RestoreIC(CKBeObject* obj, bool hierarchy)
{
}

void ModLoader::Show(CKBeObject* obj, CK_OBJECT_SHOWOPTION show, bool hierarchy)
{
}

bool ModLoader::IsIngame()
{
	return false;

}

bool ModLoader::IsPaused()
{
	return false;

}

bool ModLoader::IsPlaying()
{
	return false;

}

CKDataArray* ModLoader::GetArrayByName(CKSTRING name)
{
	return nullptr;
}

CKGroup* ModLoader::GetGroupByName(CKSTRING name)
{
	return nullptr;

}

CKMaterial* ModLoader::GetMaterialByName(CKSTRING name)
{
	return nullptr;

}

CKMesh* ModLoader::GetMeshByName(CKSTRING name)
{
	return nullptr;

}

CK2dEntity* ModLoader::Get2dEntityByName(CKSTRING name)
{
	return nullptr;

}

CK3dEntity* ModLoader::Get3dEntityByName(CKSTRING name)
{
	return nullptr;

}

CK3dObject* ModLoader::Get3dObjectByName(CKSTRING name)
{
	return nullptr;

}

CKCamera* ModLoader::GetCameraByName(CKSTRING name)
{
	return nullptr;

}

CKTargetCamera* ModLoader::GetTargetCameraByName(CKSTRING name)
{
	return nullptr;

}

CKLight* ModLoader::GetLightByName(CKSTRING name)
{
	return nullptr;

}

CKTargetLight* ModLoader::GetTargetLightByName(CKSTRING name)
{
	return nullptr;

}

CKSound* ModLoader::GetSoundByName(CKSTRING name)
{
	return nullptr;

}

CKTexture* ModLoader::GetTextureByName(CKSTRING name)
{
	return nullptr;

}

CKBehavior* ModLoader::GetScriptByName(CKSTRING name)
{
	return nullptr;

}

void ModLoader::RegisterBallType(CKSTRING ballFile, CKSTRING ballId, CKSTRING ballName, CKSTRING objName,
	float friction, float elasticity, float mass, CKSTRING collGroup, float linearDamp, float rotDamp, float force,
	float radius)
{
}

void ModLoader::RegisterFloorType(CKSTRING floorName, float friction, float elasticity, float mass, CKSTRING collGroup,
	bool enableColl)
{
}

void ModLoader::RegisterModulBall(CKSTRING modulName, bool fixed, float friction, float elasticity, float mass,
	CKSTRING collGroup, bool frozen, bool enableColl, bool calcMassCenter, float linearDamp, float rotDamp,
	float radius)
{
}

void ModLoader::RegisterModulConvex(CKSTRING modulName, bool fixed, float friction, float elasticity, float mass,
	CKSTRING collGroup, bool frozen, bool enableColl, bool calcMassCenter, float linearDamp, float rotDamp)
{
}

void ModLoader::RegisterTrafo(CKSTRING modulName)
{
}

void ModLoader::RegisterModul(CKSTRING modulName)
{
}

int ModLoader::GetModCount()
{
	return 0;
}

IMod* ModLoader::GetMod(int index)
{
	return nullptr;
}

float ModLoader::GetSRScore()
{
	return 0.0f;
}

int ModLoader::GetHSScore()
{
	return 0;
}

void ModLoader::SkipRenderForNextTick()
{
}
