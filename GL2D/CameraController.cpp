#include "CameraController.h"
#include "CameraUtil.h"
#include "MouseUtil.h"
#include <cmath>

CameraController::CameraController() {
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}

void CameraController::Update(float FT) {
	// 움직인 마우스 커서의 거리만큼 카메라 회전 각도 증가
	Rotation += mouse.x * 4;

	// 카메라 회전 각도가 0.0이 아니면 다시 0.0으로 선형 보간 복귀
	Rotation = std::lerp(Rotation, 0.0, 20 * FT);

	// 카메라를 천천히 움직인다
	Position.x = LSA_X.Update(0.05, FT * 3.0);
	Position.y = LSA_Y.Update(0.025, FT * 1.5);

	// 카메라 위치 조정
	camera.Move(Position.x, Position.y);

	// 카메라 회전
	camera.Rotate(Rotation);

	// 플레이 모드 도중에는 마우스 위치는 항상 화면 중앙을 유지
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}