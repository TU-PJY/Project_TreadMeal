#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, BlinkFace{}, EatFace{};
	GLfloat Position{};
	glm::vec2 WingPosition{};
	GLfloat Rotation{};

	// 눈 깜빡임 타이머와 눈 깜빡임 상태
	TimerUtil BlinkTimer;
	bool BlinkState{};

	// 트레드밀 위에서 움직이는 음식을 먹었을 때 활성화
	bool EatState{};

	// 날개 상하 왕복 애니메이션
	LoopSinAnimation LSA_Wing;

public:
	Erpin();
	void Update(float FT);
	void Render();
};

