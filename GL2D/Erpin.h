#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, BlinkFace{}, EatFace{};
	GLfloat Position{};
	glm::vec2 WingPosition{};
	GLfloat Rotation{};

	// �� ������ Ÿ�̸ӿ� �� ������ ����
	TimerUtil BlinkTimer;
	bool BlinkState{};

	// Ʈ����� ������ �����̴� ������ �Ծ��� �� Ȱ��ȭ
	bool EatState{};

	// ���� ���� �պ� �ִϸ��̼�
	LoopSinAnimation LSA_Wing;

public:
	Erpin();
	void Update(float FT);
	void Render();
};

