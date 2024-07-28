#include "Erpin.h"
#include "MouseUtil.h"
#include <cmath>

Erpin::Erpin() {
	SetImage(Body, "erpin");
	SetImage(Wing, "erpin_wing");
	SetImage(NormalFace, "erpin_face_normal");
	SetImage(EatFace, "erpin_face_eat");
}

void Erpin::Update(float FT) {
	// ���콺�� �����̸� �������� ��ġ�� �̵��ǰ� ȸ���Ѵ�
	Position += mouse.x * 0.25;
	Rotation += mouse.x * 10;

	// -0.4 ~ 0.4 ���̿����� �̉�
	if (Position > 0.4)
		Position = 0.4;
	else if (Position < -0.4)
		Position = -0.4;

	// ȸ�� ������ ���� ���� ����
	Rotation = std::lerp(Rotation, 0.0, 20 * FT);

	// ������ �������� ��ġ�� ���� �������� �����Ѵ�
	WingPosition = std::lerp(WingPosition, Position, 20 * FT);
}

void Erpin::Render() {
	// ������ ����
	BeginProcess(ImageRenderMode::Default);
	Move(WingPosition, 0.1);
	Rotate(Rotation);
	Scale(1.5, 1.5);
	RenderImage(Wing, 1.0, 360, 256);

	// ������ ����
	BeginProcess(ImageRenderMode::Default);
	Move(Position , 0.1);
	Rotate(Rotation);
	Scale(1.5, 1.5);
	RenderImage(Body, 1.0, 360, 256);

	// ������ ��
	// ���¿� ���� �ٸ� �̹����� ����Ѵ�
	// ���� ��Ʈ���� ��� ����� �������Ƿ� �ش� ������ ��� ����� ���� �ʰ� �ٷ� ����Ѵ�
	if (!EatState)
		RenderImage(NormalFace);
	else
		RenderImage(EatFace);
}