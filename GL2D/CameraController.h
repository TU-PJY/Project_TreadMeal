#pragma once
#include "Framework.h"

class CameraController : public BASE {
private:
	// 카메라 회전 각도, 위치
	GLfloat Rotation{};
	glm::vec2 Position{};

public:
	CameraController();
	void Update(float FT);
};

