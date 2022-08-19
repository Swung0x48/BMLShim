#include "pch.h"
#include "Gui.h"

CKBOOL InputHook::IsKeyDown(CKDWORD iKey, CKDWORD* oStamp) {
	return TRUE;
}

CKBOOL InputHook::IsKeyUp(CKDWORD iKey) {
	return TRUE;
}

CKBOOL InputHook::IsKeyToggled(CKDWORD iKey, CKDWORD* oStamp) {
	return TRUE;
}

unsigned char* InputHook::GetKeyboardState() {
	return nullptr;
}

int InputHook::GetNumberOfKeyInBuffer() {
	return 0;
}

int InputHook::GetKeyFromBuffer(int i, CKDWORD& oKey, CKDWORD* oTimeStamp) {
	return 0;
}

CKBOOL InputHook::IsMouseButtonDown(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

CKBOOL InputHook::IsMouseClicked(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

CKBOOL InputHook::IsMouseToggled(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

void InputHook::GetMouseButtonsState(CKBYTE oStates[4]) {
	
}

void InputHook::GetLastMousePosition(Vx2DVector& position) {
}

bool InputHook::IsBlock() {
	return TRUE;
}

void InputHook::SetBlock(bool block) {
}

void InputHook::Process() {

}

CKBOOL InputHook::IsKeyPressed(CKDWORD iKey) {
	return TRUE;
}

CKBOOL InputHook::IsKeyReleased(CKDWORD iKey) {
	return TRUE;
}

CKBOOL InputHook::oIsKeyPressed(CKDWORD iKey) {
	return TRUE;
}

CKBOOL InputHook::oIsKeyReleased(CKDWORD iKey) {
	return TRUE;
}

bool InputHook::InitHook() {
	return true;
}

CKBOOL InputHook::oIsKeyDown(CKDWORD iKey, CKDWORD* oStamp) {
	return TRUE;
}

CKBOOL InputHook::oIsKeyUp(CKDWORD iKey) {
	return TRUE;
}

CKBOOL InputHook::oIsKeyToggled(CKDWORD iKey, CKDWORD* oStamp) {
	return TRUE;
}

unsigned char* InputHook::oGetKeyboardState() {
	return nullptr;
}

int InputHook::oGetNumberOfKeyInBuffer() {
	return TRUE;
}

int InputHook::oGetKeyFromBuffer(int i, CKDWORD& oKey, CKDWORD* oTimeStamp) {
	return TRUE;
}

CKBOOL InputHook::oIsMouseButtonDown(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

CKBOOL InputHook::oIsMouseClicked(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

CKBOOL InputHook::oIsMouseToggled(CK_MOUSEBUTTON iButton) {
	return TRUE;
}

void InputHook::oGetMouseButtonsState(CKBYTE oStates[4]) {
}


namespace BGui {

	NAKED char VxScanCodeToAscii(DWORD scancode, unsigned char keystate[256]) {
		JUMP(0x24284D20);
	}

	Element::Element(CKSTRING name) {
	}

	Element::~Element() {
	}

	Vx2DVector Element::GetPosition() {
		Vx2DVector res;
		return res;
	}

	void Element::SetPosition(Vx2DVector pos) {
	}

	Vx2DVector Element::GetSize() {
		Vx2DVector res;
		return res;
	}

	void Element::SetSize(Vx2DVector size) {
	}

	int Element::GetZOrder() {
		return 0;
	}

	void Element::SetZOrder(int z) {
	}

	bool Element::IsVisible() {
		return false;
	}

	void Element::SetVisible(bool visible) {
	}

	Text::Text(CKSTRING name) : Element(name) {
	}

	Text::~Text() {
	}

	void Text::UpdateFont() {
	}

	Vx2DVector Text::GetPosition() {
		Vx2DVector res;
		return res;
	}

	void Text::SetPosition(Vx2DVector pos) {
	}

	Vx2DVector Text::GetSize() {
		Vx2DVector res;
		return res;
	}

	void Text::SetSize(Vx2DVector size) {
	}

	int Text::GetZOrder() {
		return 0;
	}

	void Text::SetZOrder(int z) {
	}

	bool Text::IsVisible() {
		return false;
	}

	void Text::SetVisible(bool visible) {
	}

	CKSTRING Text::GetText() {
		return nullptr;
	}

	void Text::SetText(CKSTRING text) {
	}

	void Text::SetFont(CKSTRING FontName, int FontSize, int Weight, CKBOOL italic, CKBOOL underline) {
	}

	void Text::SetAlignment(CKSPRITETEXT_ALIGNMENT align) {
	}

	CKDWORD Text::GetTextColor() {
		return 0;
	}

	void Text::SetTextColor(CKDWORD color) {
	}

	Panel::Panel(CKSTRING name) : Element(name) {
	}

	Panel::~Panel() {
	}

	VxColor Panel::GetColor() {
		return VxColor();
	}

	void Panel::SetColor(VxColor color) {
	}

	Label::Label(CKSTRING name) : Element(name) {
	}

	Label::~Label() {
	}

	CKSTRING Label::GetText() {
		return nullptr;
	}

	void Label::SetText(CKSTRING text) {
	}

	ExecuteBB::FontType Label::GetFont() {
		return ExecuteBB::NOFONT;
	}

	void Label::SetFont(ExecuteBB::FontType font) {
	}

	void Label::SetAlignment(int align) {
	}

	int Label::GetTextFlags() {
		return 0;
	}

	void Label::SetTextFlags(int flags) {
	}

	void Label::SetOffset(Vx2DVector offset) {
	}

	void Label::Process() {
	}

	Button::Button(CKSTRING name) : Label(name) {
	}

	ButtonType Button::GetType() {
		return BUTTON_NORMAL;
	}

	void Button::SetType(ButtonType type) {
	}

	bool Button::IsActive() {
		return false;
	}

	void Button::SetActive(bool active) {
	}

	void Button::InvokeCallback() {
	}

	void Button::SetCallback(std::function<void()> callback) {
	}

	void Button::OnMouseEnter() {
	}

	void Button::OnMouseLeave() {
	}

	Input::Input(CKSTRING name) : Label(name) {
	}

	void Input::InvokeCallback(CKDWORD key) {
	}

	void Input::SetCallback(std::function<void(CKDWORD)> callback) {
	}

	void Input::OnCharTyped(CKDWORD key) {
	}

	CKSTRING Input::GetText() {
		return nullptr;
	}

	void Input::SetText(CKSTRING text) {
	}

	void Input::GetFocus() {
	}

	void Input::LoseFocus() {
	}

	KeyInput::KeyInput(CKSTRING name) : Input(name) {
	}

	void KeyInput::OnCharTyped(CKDWORD key) {
	}

	CKKEYBOARD KeyInput::GetKey() {
		return CKKEY_0;
	}

	void KeyInput::SetKey(CKKEYBOARD key) {
	}

	void KeyInput::GetFocus() {
	}

	void KeyInput::LoseFocus() {
	}

	Gui::Gui() {
	}

	Gui::~Gui()
	{
	}

	void Gui::OnCharTyped(CKDWORD key) {
	}

	void Gui::OnMouseDown(float x, float y, CK_MOUSEBUTTON key) {
	}

	void Gui::OnMouseWheel(float w) {

	}

	void Gui::OnMouseMove(float x, float y, float lx, float ly) {
	}

	bool Gui::Intersect(float x, float y, Element* element) {
		return false;
	}

	Button* Gui::AddNormalButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;
	}

	Button* Gui::AddBackButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;
	}

	Button* Gui::AddSettingButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;
	}

	Button* Gui::AddLevelButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;
	}

	Button* Gui::AddSmallButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;

	}

	Button* Gui::AddLeftButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;

	}

	Button* Gui::AddRightButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;

	}

	Button* Gui::AddPlusButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;

	}

	Button* Gui::AddMinusButton(CKSTRING name, float yPos, float xPos, std::function<void()> callback) {
		return nullptr;

	}

	Button* Gui::AddKeyBgButton(CKSTRING name, float yPos, float xPos) {
		return nullptr;

	}

	Panel* Gui::AddPanel(CKSTRING name, VxColor color, float xPos, float yPos, float xSize, float ySize) {
		return nullptr;

	}

	Label* Gui::AddTextLabel(CKSTRING name, CKSTRING text, ExecuteBB::FontType font, float xPos, float yPos, float xSize, float ySize) {
		return nullptr;

	}

	Text* Gui::AddText(CKSTRING name, CKSTRING text, float xPos, float yPos, float xSize, float ySize) {
		return nullptr;

	}

	Input* Gui::AddTextInput(CKSTRING name, ExecuteBB::FontType font, float xPos, float yPos, float xSize, float ySize, std::function<void(CKDWORD)> callback) {
		return nullptr;
	}

	std::pair<Button*, KeyInput*> Gui::AddKeyButton(CKSTRING name, CKSTRING text, float yPos, float xPos, std::function<void(CKDWORD)> callback) {
		return { nullptr, nullptr };
	}

	std::pair<Button*, Button*> Gui::AddYesNoButton(CKSTRING name, float yPos, float x1Pos, float x2Pos, std::function<void(bool)> callback) {
		return { nullptr, nullptr };

	}

	void Gui::Process() {
	}

	void Gui::SetVisible(bool visible) {
	}

	bool Gui::CanBeBlocked() {
		return false;
	}

	void Gui::SetCanBeBlocked(bool block) {
	}

	void Gui::SetFocus(Input* input) {
	}

	void Gui::InitMaterials() {
	}

	void Gui::OnScreenModeChanged() {
	}
}