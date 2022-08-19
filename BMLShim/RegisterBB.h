#pragma once
#include "virtools/CKAll.h"

class BML_EXPORT HookParams {
public:
	HookParams(CKBehavior* beh) {}

	void SetParamObject(int pos, CKObject* value) { }
	void SetParamString(int pos, CKSTRING value) { }
	template<typename T>
	void SetParamValue(int pos, T value) {
	}

	CKObject* GetParamObject(int pos) { return nullptr; }
	CKSTRING GetParamString(int pos) { return nullptr; }
	template<typename T>
	T GetParamValue(int pos) {
		T res;
		return res;
	}

	void ActivateInput(int pos) { }
	void DeactivateInput(int pos) { }
	void ActivateOutput(int pos) { }
	void DeactivateOutput(int pos) { }
};

class BML_EXPORT BBBuilder {
public:
	BBBuilder* SetName(CKSTRING name) { return this; }
	BBBuilder* SetDescription(CKSTRING desc) { return this; }
	BBBuilder* SetCategory(CKSTRING cate) { return this; }
	BBBuilder* SetGuid(CKGUID guid) { return this; }

	BBBuilder* SetAuthor(CKSTRING author) { return this; }
	BBBuilder* SetAuthorGuid(CKGUID guid) { return this; }
	BBBuilder* SetVersion(CKDWORD version) { return this; }
	BBBuilder* SetClassID(CK_CLASSID id) { return this; }

	BBBuilder* SetBehaviorFlags(CKDWORD flags) { return this; }
	BBBuilder* SetFlags(CK_BEHAVIORPROTOTYPE_FLAGS flags) { return this; }
	BBBuilder* SetFunction(CKBEHAVIORFCT function) { return this; }
	BBBuilder* SetCallback(CKBEHAVIORCALLBACKFCT fct, CKDWORD CallbackMask = CKCB_BEHAVIORALL, void* param = NULL)
	{
		return this;
	}

	BBBuilder* AddInput(CKSTRING name) { return this; }
	BBBuilder* AddOutput(CKSTRING name) { return this; }
	BBBuilder* AddInputParam(CKSTRING name, CKGUID type) { return this; }
	BBBuilder* AddOutputParam(CKSTRING name, CKGUID type) { return this; }

	CKObjectDeclaration* Build() { return nullptr; }
	CKDLL_CREATEPROTOFUNCTION BuildProto() { return nullptr; }
	virtual CKBEHAVIORFCT BuildFunction() { return nullptr; }
};


class BML_EXPORT HookBuilder : public BBBuilder {
public:
	HookBuilder() {
	}

	HookBuilder* SetName(CKSTRING name) {return this; }
	HookBuilder* SetDescription(CKSTRING desc) {return this; }
	HookBuilder* SetCategory(CKSTRING cate) { return this; }
	HookBuilder* SetGuid(CKGUID guid) { return this; }

	HookBuilder* SetCancellable() { return this; }
	HookBuilder* AddInputParam(CKSTRING name, CKGUID type) { return this; }
	HookBuilder* AddModifiableParam(CKSTRING name, CKGUID type) {
		return this;
	}

	virtual CKBEHAVIORFCT BuildFunction() override { return nullptr; }

	typedef std::function<bool(HookParams*)> ProcessFunction;
	HookBuilder* SetProcessFunction(ProcessFunction function) { return this; }
};

#ifdef BML_EXPORTS

#define BML_ONPRESTARTMENU_GUID CKGUID(0x2c8d46ee,0x784c071f)
#define BML_ONPOSTSTARTMENU_GUID CKGUID(0x4a404bf4,0x1dd97e55)
#define BML_ONEXITGAME_GUID CKGUID(0x31e95dd8,0x6a0a421b)
#define BML_ONPRELOADLEVEL_GUID CKGUID(0x3d723f8f,0x71945d10)
#define BML_ONPOSTLOADLEVEL_GUID CKGUID(0x11ee2f9e,0x2a0f5047)
#define BML_ONSTARTLEVEL_GUID CKGUID(0x2da6502c,0x404b2733)
#define BML_ONPRERESETLEVEL_GUID CKGUID(0x79815eec,0x51e70736)
#define BML_ONPOSTRESETLEVEL_GUID CKGUID(0x58170b9,0x59c14963)
#define BML_ONPAUSELEVEL_GUID CKGUID(0x523110b,0x14a67134)
#define BML_ONUNPAUSELEVEL_GUID CKGUID(0x4c91714e,0x67305482)
#define BML_ONPREEXITLEVEL_GUID CKGUID(0xfa02db3,0x54516676)
#define BML_ONPOSTEXITLEVEL_GUID CKGUID(0x863303a,0x37a377c9)
#define BML_ONPRENEXTLEVEL_GUID CKGUID(0x180e44ce,0x40bc34b4)
#define BML_ONPOSTNEXTLEVEL_GUID CKGUID(0x51e32ce4,0x3c92b0d)
#define BML_ONDEAD_GUID CKGUID(0x681356d8,0x60076e9b)
#define BML_ONPREENDLEVEL_GUID CKGUID(0x338b4070,0x1a0a1016)
#define BML_ONPOSTENDLEVEL_GUID CKGUID(0x6c5321a6,0x71e42a21)

#define BML_ONCOUNTERACTIVE_GUID CKGUID(0x2f712e25,0x74c80214)
#define BML_ONCOUNTERINACTIVE_GUID CKGUID(0x55ea4b9e,0xc497abe)
#define BML_ONBALLNAVACTIVE_GUID CKGUID(0x518d4300,0x4ccc36f3)
#define BML_ONBALLNAVINACTIVE_GUID CKGUID(0x7e2777c2,0x5960750a)
#define BML_ONCAMNAVACTIVE_GUID CKGUID(0x11cc62b2,0x61c93140)
#define BML_ONCAMNAVINACTIVE_GUID CKGUID(0x30b77290,0x150c2d6a)
#define BML_ONBALLOFF_GUID CKGUID(0x47c51895,0x4ff4616e)
#define BML_ONPRECHECKPOINT_GUID CKGUID(0x76f824e9,0x5b903bc7)
#define BML_ONPOSTCHECKPOINT_GUID CKGUID(0xbf6732a,0x3bb33205)
#define BML_ONLEVELFINISH_GUID CKGUID(0x40a0230b,0x60634050)
#define BML_ONGAMEOVER_GUID CKGUID(0xc8866ec,0xd73214b)
#define BML_ONEXTRAPOINT_GUID CKGUID(0x511b3834,0x75ab7ecf)
#define BML_ONPRESUBLIFE_GUID CKGUID(0x2f420ffc,0x1f79585d)
#define BML_ONPOSTSUBLIFE_GUID CKGUID(0x343274b3,0x4ac024d4)
#define BML_ONPRELIFEUP_GUID CKGUID(0x6f4406ba,0x6aa764a7)
#define BML_ONPOSTLIFEUP_GUID CKGUID(0x4c770ce7,0x5418125d)

#define BML_MODSMENU_GUID CKGUID(0x6ac12ce,0x52dc6e9d)

#define TT_PUSHBUTTON2 CKGUID(0x14d325d1,0x6748654e)
#define TT_SETPHYSICSFORCE CKGUID(0x56e20c57,0x0b926068)
#define TT_PHYSICALIZE CKGUID(0x7522370e,0x37ec15ec)
#define TT_PHYSICSIMPLUSE CKGUID(0xc7e39bb,0x16db20d5)
#define TT_PHYSICSWAKEUP CKGUID(951603637, 1925870764)

#define VT_TEXT2D CKGUID(0x55b29fe,0x662d5ca0)
#define VT_KEYEVENT CKGUID(0x1af2274b,0x6b8c1524)
#define VT_OBJECTLOAD CKGUID(0x7bd977d7,0x26396c0c)
#define VT_BINARYSWITCH CKGUID(0xeb506901,0x984afccc)
#define VT_SETATTRIBUTE CKGUID(0x373040f2,0x5e01b34)
#define VT_IDENTITY CKGUID(0x15151652, 0xaeefffd5)
#define VT_TIMER CKGUID(0xa2a5a63a, 0xe4e7e8e5)
#define VT_ACTIVATESCRIPT CKGUID(0x4c7e7bc3, 0x0b693155)
#define VT_KEEPACTIVE CKGUID(0x7160133a,0x1f2532fe)
#define VT_PERSECOND CKGUID(0x448e54ce, 0x75a655c5)
#define VT_REMOVEATTRIBUTE CKGUID(0x6b6340c4,0x61e94a41)

#endif