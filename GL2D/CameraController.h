#pragma once
#include "Framework.h"

class CameraController : public BASE {
private:
	// ī�޶� ȸ�� ����, ��ġ
	GLfloat Rotation{};
	glm::vec2 Position{};

public:
	CameraController();
	void Update(float FT);
};

