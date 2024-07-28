#pragma once
#include "Framework.h"

class CameraController : public BASE {
private:
	// 카메라 회전 각도, 위치
	GLfloat Rotation{};
	glm::vec2 Position{};

	// 카메라 움직임 애니메이션 유틸
	LoopSinAnimation LSA_X, LSA_Y;

public:
	CameraController();
	void Update(float FT);
};

