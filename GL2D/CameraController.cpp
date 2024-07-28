#include "CameraController.h"
#include "CameraUtil.h"
#include "MouseUtil.h"
#include <cmath>

CameraController::CameraController() {
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}

void CameraController::Update(float FT) {
	// ������ ���콺 Ŀ���� �Ÿ���ŭ ī�޶� ȸ�� ���� ����
	Rotation += mouse.x * 4;

	// ī�޶� ȸ�� ������ 0.0�� �ƴϸ� �ٽ� 0.0���� ���� ���� ����
	Rotation = std::lerp(Rotation, 0.0, 20 * FT);

	// ī�޶� õõ�� �����δ�
	Position.x = LSA_X.Update(0.05, FT * 3.0);
	Position.y = LSA_Y.Update(0.025, FT * 1.5);

	// ī�޶� ��ġ ����
	camera.Move(Position.x, Position.y);

	// ī�޶� ȸ��
	camera.Rotate(Rotation);

	// �÷��� ��� ���߿��� ���콺 ��ġ�� �׻� ȭ�� �߾��� ����
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}