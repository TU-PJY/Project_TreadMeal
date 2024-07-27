#pragma once
#include "Framework.h"

class CameraController : public BASE {
public:
	// 카메라 회전 각도, 위치
	GLfloat Rotation{};
	glm::vec2 Position{};

	// 현재 마우스 위치
	GLfloat MousePosition{};

	CameraController();
	void Update(float FT);
};

