#pragma once
#include "Framework.h"

class CameraController : public BASE {
public:
	// ī�޶� ȸ�� ����, ��ġ
	GLfloat Rotation{};
	glm::vec2 Position{};

	// ���� ���콺 ��ġ
	GLfloat MousePosition{};

	CameraController();
	void Update(float FT);
};

