#pragma once
#include "Framework.h"

class CameraController : public BASE {
private:
	// ī�޶� ȸ�� ����, ��ġ
	GLfloat Rotation{};
	glm::vec2 Position{};

	// ī�޶� ������ �ִϸ��̼� ��ƿ
	LoopSinAnimation LSA_X, LSA_Y;

public:
	CameraController();
	void Update(float FT);
};

