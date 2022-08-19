#pragma once
#include "ExecuteBB.h"
#include <string>
#include <vector>
#include <functional>

#pragma warning(push)
#pragma warning(disable:4251)

namespace BGui {

	char VxScanCodeToAscii(DWORD scancode, unsigned char keystate[256]);

	enum ButtonType {
		BUTTON_NORMAL,
		BUTTON_BACK,
		BUTTON_SETTING,
		BUTTON_LEVEL,
		BUTTON_KEY,
		BUTTON_KEYSEL,
		BUTTON_SMALL,
		BUTTON_LEFT,
		BUTTON_RIGHT,
		BUTTON_PLUS,
		BUTTON_MINUS,
	};

	class BML_EXPORT Element {
		friend class Gui;
	public:
		Element(CKSTRING name);
		virtual ~Element();

		virtual Vx2DVector GetPosition();
		virtual void SetPosition(Vx2DVector pos);
		virtual Vx2DVector GetSize();
		virtual void SetSize(Vx2DVector size);
		virtual int GetZOrder();
		virtual void SetZOrder(int z);

		virtual bool IsVisible();
		virtual void SetVisible(bool visible);

		virtual void Process() {};
	};

	class BML_EXPORT Text : private Element {
		friend class Gui;
	public:
		Text(CKSTRING name);
		virtual ~Text();

		virtual Vx2DVector GetPosition();
		virtual void SetPosition(Vx2DVector pos);
		virtual Vx2DVector GetSize();
		virtual void SetSize(Vx2DVector size);
		virtual int GetZOrder();
		virtual void SetZOrder(int z);

		virtual bool IsVisible();
		virtual void SetVisible(bool visible);

		CKSTRING GetText();
		void SetText(CKSTRING text);
		void SetFont(CKSTRING FontName, int FontSize, int Weight, CKBOOL italic, CKBOOL underline);
		void SetAlignment(CKSPRITETEXT_ALIGNMENT align);
		CKDWORD GetTextColor();
		void SetTextColor(CKDWORD color);

		void UpdateFont();
	};

	class BML_EXPORT Panel : public Element {
		friend class Gui;
	public:
		Panel(CKSTRING name);
		virtual ~Panel();

		VxColor GetColor();
		void SetColor(VxColor color);
	};

	class BML_EXPORT Label : public Element {
		friend class Gui;
	public:
		Label(CKSTRING name);
		virtual ~Label();

		virtual CKSTRING GetText();
		virtual void SetText(CKSTRING text);
		ExecuteBB::FontType GetFont();
		void SetFont(ExecuteBB::FontType font);
		void SetAlignment(int align);
		int GetTextFlags();
		void SetTextFlags(int flags);
		void SetOffset(Vx2DVector offset);

		virtual void Process() override;
	};

	class BML_EXPORT Button : public Label {
		friend class Gui;
	public:
		Button(CKSTRING name);

		ButtonType GetType();
		void SetType(ButtonType type);
		bool IsActive();
		void SetActive(bool active);
		void InvokeCallback();
		void SetCallback(std::function<void()> callback);

		void OnMouseEnter();
		void OnMouseLeave();
	};

	class BML_EXPORT Input : public Label {
		friend class Gui;
	public:
		Input(CKSTRING name);
		void InvokeCallback(CKDWORD);
		void SetCallback(std::function<void(CKDWORD)> callback);
		virtual void OnCharTyped(CKDWORD key);
		virtual CKSTRING GetText() override;
		virtual void SetText(CKSTRING text) override;
		virtual void GetFocus();
		virtual void LoseFocus();
	};

	class BML_EXPORT KeyInput : public Input {
		friend class Gui;
	public:
		KeyInput(CKSTRING name);

		virtual void OnCharTyped(CKDWORD key);
		CKKEYBOARD GetKey();
		void SetKey(CKKEYBOARD key);
		virtual void GetFocus();
		virtual void LoseFocus();
	};

	class BML_EXPORT Gui {
	public:
		Gui();
		~Gui();

		Button* AddNormalButton(CKSTRING name, CKSTRING text, float yPos, float xPos = 0.35f, std::function<void()> callback = []() {});
		Button* AddBackButton(CKSTRING name, CKSTRING text = "Back", float yPos = 0.85f, float xPos = 0.4031f, std::function<void()> callback = []() {});
		Button* AddSettingButton(CKSTRING name, CKSTRING text, float yPos, float xPos = 0.35f, std::function<void()> callback = []() {});
		Button* AddLevelButton(CKSTRING name, CKSTRING text, float yPos, float xPos = 0.4031f, std::function<void()> callback = []() {});
		Button* AddSmallButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback = []() {});
		Button* AddLeftButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback = []() {});
		Button* AddRightButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback = []() {});
		Button* AddPlusButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback = []() {});
		Button* AddMinusButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback = []() {});
		Button* AddKeyBgButton(CKSTRING name, float yPos, float xPos);

		Panel* AddPanel(CKSTRING name, VxColor color, float xPos, float yPos, float xSize, float ySize);
		Label* AddTextLabel(CKSTRING name, CKSTRING text, ExecuteBB::FontType font, float xPos, float yPos, float xSize, float ySize);
		Text* AddText(CKSTRING name, CKSTRING text, float xPos, float yPos, float xSize, float ySize);
		Input* AddTextInput(CKSTRING name, ExecuteBB::FontType font, float xPos, float yPos, float xSize, float ySize, std::function<void(CKDWORD)> callback = [](CKDWORD) {});
		std::pair<Button*, KeyInput*> AddKeyButton(CKSTRING name, CKSTRING text, float yPos, float xPos = 0.35f, std::function<void(CKDWORD)> callback = [](CKDWORD) {});
		std::pair<Button*, Button*> AddYesNoButton(CKSTRING name, float yPos, float x1Pos, float x2Pos, std::function<void(bool)> callback = [](bool) {});

		virtual void OnCharTyped(CKDWORD key);
		virtual void OnMouseDown(float x, float y, CK_MOUSEBUTTON key);
		virtual void OnMouseWheel(float w);
		virtual void OnMouseMove(float x, float y, float lx, float ly);
		virtual void OnScreenModeChanged();

		virtual void Process();
		virtual void SetVisible(bool visible);
		bool CanBeBlocked();
		void SetCanBeBlocked(bool block);
		void SetFocus(Input* input);
		bool Intersect(float x, float y, Element* element);

		static void InitMaterials();
	};
}

class BML_EXPORT InputHook : public CKInputManager {
public:
	CKBOOL IsKeyDown(CKDWORD iKey, CKDWORD* oStamp = NULL);
	CKBOOL IsKeyUp(CKDWORD iKey);
	CKBOOL IsKeyToggled(CKDWORD iKey, CKDWORD* oStamp = NULL);
	unsigned char* GetKeyboardState();
	int GetNumberOfKeyInBuffer();
	int GetKeyFromBuffer(int i, CKDWORD& oKey, CKDWORD* oTimeStamp = NULL);
	CKBOOL IsMouseButtonDown(CK_MOUSEBUTTON iButton);
	CKBOOL IsMouseClicked(CK_MOUSEBUTTON iButton);
	CKBOOL IsMouseToggled(CK_MOUSEBUTTON iButton);
	void GetMouseButtonsState(CKBYTE oStates[4]);
	void GetLastMousePosition(Vx2DVector& position);

	CKBOOL oIsKeyDown(CKDWORD iKey, CKDWORD* oStamp = NULL);
	CKBOOL oIsKeyUp(CKDWORD iKey);
	CKBOOL oIsKeyToggled(CKDWORD iKey, CKDWORD* oStamp = NULL);
	unsigned char* oGetKeyboardState();
	int oGetNumberOfKeyInBuffer();
	int oGetKeyFromBuffer(int i, CKDWORD& oKey, CKDWORD* oTimeStamp = NULL);
	CKBOOL oIsMouseButtonDown(CK_MOUSEBUTTON iButton);
	CKBOOL oIsMouseClicked(CK_MOUSEBUTTON iButton);
	CKBOOL oIsMouseToggled(CK_MOUSEBUTTON iButton);
	void oGetMouseButtonsState(CKBYTE oStates[4]);

	static bool InitHook();

	typedef CKBOOL(InputHook::* IsKeyDownFunc)(CKDWORD, CKDWORD*);
	typedef CKBOOL(InputHook::* IsKeyUpFunc)(CKDWORD);
	typedef unsigned char* (InputHook::* GetKeyboardStateFunc)();
	typedef int(InputHook::* GetNumberOfKeyInBufferFunc)();
	typedef int(InputHook::* GetKeyFromBufferFunc)(int, CKDWORD&, CKDWORD*);
	typedef CKBOOL(InputHook::* IsMouseDownFunc)(CK_MOUSEBUTTON);
	typedef void(InputHook::* GetMouseButtonsStateFunc)(CKBYTE[4]);

	static bool IsBlock();
	static void SetBlock(bool block);
	void Process();

	CKBOOL IsKeyPressed(CKDWORD iKey);
	CKBOOL IsKeyReleased(CKDWORD iKey);
	CKBOOL oIsKeyPressed(CKDWORD iKey);
	CKBOOL oIsKeyReleased(CKDWORD iKey);
};