#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, BlinkFace{}, EatFace1{}, EatFace2{};
	GLfloat Position{};
	glm::vec2 WingPosition{};
	GLfloat Rotation{};

	// �� ������ Ÿ�̸ӿ� �� ������ ����
	TimerUtil BlinkTimer;
	bool BlinkState{};

	// �Ա� �ִϸ��̼� ������ Ÿ�̸�, �Ա� �ִϸ��̼� ���� Ÿ�̸�
	TimerUtil EatAnimationTimer;
	TimerUtil AnimationTimer;

	// Ʈ����� ������ �����̴� ������ �Ծ��� �� Ȱ��ȭ
	bool EatState{};
	bool EatStateTimerResetState = true;
	int Frame = 0;  // �̹��� �ݺ� ����� ���� ����

	// �Ա� ���� �ִϸ��̼ǿ� ����ϴ� ��
	GLfloat EatWobbleValue{};

	// ���� ���� �պ� �ִϸ��̼�, �Ա� ��鸲 �ִϸ��̼�
	LoopSinAnimation LSA_Wing, LSA_Wobble;

	AABB aabb;

public:
	Erpin();
	AABB GetAABB();
	void SetEatState();
	void Update(float FT);
	void Render();
};

