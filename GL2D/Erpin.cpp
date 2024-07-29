#include "Erpin.h"
#include "MouseUtil.h"
#include <cmath>

Erpin::Erpin() {
	SetImage(Body, "erpin");
	SetImage(Wing, "erpin_wing");
	SetImage(NormalFace, "erpin_face_normal");
	SetImage(BlinkFace, "erpin_face_blink");
	SetImage(EatFace1, "erpin_face_eat_1");
	SetImage(EatFace2, "erpin_face_eat_2");

	aabb.Init();
}

AABB Erpin::GetAABB() {
	return aabb;
}

// �Ա� ���°� Ȱ��ȭ �ǰ� �Ա� �ִϸ��̼� ���� Ÿ�̸Ӱ� �ʱ�ȭ�ȴ�
void Erpin::SetEatState() {
	EatState = true;
	EatStateTimerResetState = false;
	AnimationTimer.Reset();
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

	// ������ x��ġ�� �������� ��ġ�� ���� �������� �����Ѵ�
	WingPosition.x = std::lerp(WingPosition.x, Position, 20 * FT);

	// ������ y��ġ�� ���� �պ� �Ѵ�
	WingPosition.y = LSA_Wing.Update(0.05, FT * 2);

	// �� ������ ������Ʈ
	// 3�ʸ��� ���� �����δ�
	// �Ա� ���°� �ƴ� ���� ������Ʈ
	if (!EatState) {
		BlinkTimer.Update(FT);
		if (!BlinkState && BlinkTimer.Sec() >= 3) {
			BlinkState = true;
			BlinkTimer.Reset();
		}

		// �� ������ Ȱ��ȭ ������ ���� 0.2���� �� �������� ��Ȱ��ȭ �Ѵ�
		else if (BlinkState && BlinkTimer.MiliSec() >= 0.2) {
			BlinkState = false;
			BlinkTimer.Reset();
		}
	}

	// �Ա� ���� �ִϸ��̼� ������Ʈ
	if (EatState) {
		// 0.5�ʵ��� �Ա� �ִϸ��̼��� ����Ѵ�
		EatAnimationTimer.Update(FT * 20);
		AnimationTimer.Update(FT);
		Frame = int(EatAnimationTimer.MiliSec(2)) % 2;
		EatWobbleValue = LSA_Wobble.Update(0.05, FT * 40);
		
		// 0.5�ʰ� ������ ���°� �⺻ ���·� �ʱ�ȭ �ȴ�
		if (AnimationTimer.MiliSec() >= 0.5) {
			EatAnimationTimer.Reset();
			AnimationTimer.Reset();
			LSA_Wobble.Reset();
			EatWobbleValue = 0.0;
			EatState = false;
		}
	}

	// aabb �ٿ�� �ڽ� ������Ʈ
	aabb.Update(Position, -0.1, 0.1, 0.05);
}

void Erpin::Render() {
	// ������ ����
	BeginProcess(ImageRenderMode::Default);
	Move(WingPosition.x, 0.1 + WingPosition.y);
	Rotate(Rotation);
	Scale(1.5, 1.5);
	RenderImage(Wing, 1.0, 360, 256);

	// ������ ����
	BeginProcess(ImageRenderMode::Default);
	Move(Position , 0.1 + EatWobbleValue * 0.2);
	Rotate(Rotation);
	Scale(1.5, 1.5 + EatWobbleValue);
	RenderImage(Body, 1.0, 360, 256);

	// ������ ��
	// ���¿� ���� �ٸ� �̹����� ����Ѵ�
	// ���� ��Ʈ���� ��� ����� �������Ƿ� �ش� ������ ��� ����� ���� �ʰ� �ٷ� ����Ѵ�
	if (!EatState) {
		if (BlinkState)
			RenderImage(BlinkFace);
		else
			RenderImage(NormalFace);
	}
	else {
		if(Frame == 1)
			RenderImage(EatFace1);

		else if(Frame == 0)
			RenderImage(EatFace2);
	}

	// aabb �ٿ��ڽ� ������
	aabb.BeginProcess();
	aabb.Move(Position, -0.1);
	aabb.Scale(0.1, 0.05);
	aabb.Render(true);
}