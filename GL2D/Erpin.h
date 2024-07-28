#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, EatFace{};
	GLfloat Position{};
	GLfloat WingPosition{};
	GLfloat Rotation{};

	// 트레드밀 위에서 움직이는 음식을 먹었을 때 활성화
	bool EatState{};

public:
	Erpin();
	void Update(float FT);
	void Render();
};

