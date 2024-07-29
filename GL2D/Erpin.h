#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, BlinkFace{}, EatFace1{}, EatFace2{};
	GLfloat Position{};
	glm::vec2 WingPosition{};
	GLfloat Rotation{};

	// 눈 깜빡임 타이머와 눈 깜빡임 상태
	TimerUtil BlinkTimer;
	bool BlinkState{};

	// 먹기 애니메이션 프레임 타이머, 먹기 애니메이션 유지 타이머
	TimerUtil EatAnimationTimer;
	TimerUtil AnimationTimer;

	// 트레드밀 위에서 움직이는 음식을 먹었을 때 활성화
	bool EatState{};
	bool EatStateTimerResetState = true;
	int Frame = 0;  // 이미지 반복 재생을 위한 정수

	// 먹기 상태 애니메이션에 사용하는 값
	GLfloat EatWobbleValue{};

	// 날개 상하 왕복 애니메이션, 먹기 흔들림 애니메이션
	LoopSinAnimation LSA_Wing, LSA_Wobble;

	AABB aabb;

public:
	Erpin();
	AABB GetAABB();
	void SetEatState();
	void Update(float FT);
	void Render();
};

