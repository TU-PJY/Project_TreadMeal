#include "PlayMode.h"
#include "Framework.h"
#include "MouseUtil.h"
#include "CameraUtil.h"

#include "Treadmil.h"

MouseUtil mouse;

void Play_Mode::SetController() {
	glutMotionFunc(MouseMotion);
	glutPassiveMotionFunc(MousePassiveMotion);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseWheelFunc(ProcessMouseWheel);
	glutMouseFunc(ProcessMouse);
	glutSpecialFunc(SpecialKeyDown);
	glutSpecialUpFunc(SpecialKeyUp);
}

std::string Play_Mode::PlayMode() {
	fw.AddObject(new Treadmil, "treadmil", Layer::L3);

	return __func__;
}

void Play_Mode::ProcessKeyboard(unsigned char KEY, int S_KEY, bool KeyDown, bool SpecialKey) {
	// Normal Key Down
	if (KeyDown && !SpecialKey) {
		switch (KEY) {
		case 27:
			glutDestroyWindow(1);
			break;
		}
	}
}

void Play_Mode::ProcessMouse(int button, int state, int x, int y) {
}

void Play_Mode::ProcessMouseWheel(int button, int Wheel, int x, int y) {
}

void Play_Mode::KeyDown(unsigned char KEY, int x, int y) {
	ProcessKeyboard(KEY, NULL, true, false);
}

void Play_Mode::KeyUp(unsigned char KEY, int x, int y) {
	ProcessKeyboard(KEY, NULL, false, false);
}

void Play_Mode::SpecialKeyUp(int KEY, int x, int y) {
	ProcessKeyboard(NULL, KEY, true, true);
}

void Play_Mode::SpecialKeyDown(int KEY, int x, int y) {
	ProcessKeyboard(NULL, KEY, false, true);
}

void Play_Mode::MouseMotion(int x, int y) {
	mouse.ConvertPosition(x, y);
}

void Play_Mode::MousePassiveMotion(int x, int y) {
	mouse.ConvertPosition(x, y);
}