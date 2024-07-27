#include "CameraController.h"
#include "CameraUtil.h"
#include "MouseUtil.h"
#include <cmath>

CameraController::CameraController() {
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}

void CameraController::Update(float FT) {
	// �÷��� ��� ���߿��� ���콺 ��ġ�� �׻� ȭ�� �߾��� ����
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);

	// ������ ���콺 Ŀ���� �Ÿ���ŭ ī�޶� ȸ�� ���� ����
	Rotation += mouse.x * 2;

	// ī�޶� ȸ�� ������ 0.0�� �ƴϸ� �ٽ� 0.0���� ���� ���� ����
	Rotation = std::lerp(Rotation, 0.0, 20 * FT);

	// ī�޶� ȸ��
	camera.Rotate(Rotation);
}