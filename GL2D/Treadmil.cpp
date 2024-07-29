#include "Treadmil.h"

Treadmil::Treadmil() {
	//SetImage(Body, "treadmil_debug");
	SetImage(Body, "treadmil");
	SetImage(Stripe, "treadmil_prop");

	// �ʱ� �ӵ� 0.5
	MoveSpeed = 1.0;
}

GLfloat Treadmil::GetSpeed() {
	return MoveSpeed;
}

void Treadmil::Render() {
	//// Ʈ����� ���� �� ������Ʈ�� �÷� Ŭ���� �Ѵ�
	BeginColorClipping();

	// Ʈ�����
	BeginProcess(ImageRenderMode::Default);
	Move(0.0, -0.2);
	Scale(2.0, 2.0);
	RenderImage(Body, 1.0, 400, 350);

	SetColorClipping();

	// �� ������Ʈ
	// ���� �̵��� ���� ũ�Ⱑ ���� �۾����� �۾��� ��ġ ��ŭ x������ �̵��Ѵ�
	// 1�̸� ������ ����, -1�̸� ���� ���⿡ ������
	BeginProcess(ImageRenderMode::Default);
	Scale(StripeSize, StripeSize);

	if (StripeDir == 1) {
		Move(StripeX + ((0.4 - StripeSize) * 0.2), StripeY - (0.4 - StripeSize) * 0.2);
		RenderImage(Stripe, 1.0, 100, 150);
	}

	else {
		Move(StripeX - ((0.4 - StripeSize) * 0.2), StripeY - (0.4 - StripeSize) * 0.2);
		RenderImage(Stripe, 1.0, 100, 150, Flip::Vertical);
	}

	EndColorClipping();
}

void Treadmil::Update(float FT) {
	// �־��� ������ ������Ʈ �̵�
	MoveForward(StripeX, StripeY, MoveSpeed, MoveDegree, FT);
	StripeSize -= MoveSpeed * 0.05 * FT;

	// ���̰� 0.3 �̻� �Ǹ� ���� ����� ��ġ�� �ݴ�� ��ȯ
	if (StripeY >= 0.3) {
		if (StripeDir == 1) {
			StripeX = -0.62;
			MoveDegree = 77.1;
		}

		else {
			StripeX = 0.62;
			MoveDegree = 102.9;
		}

		StripeDir *= -1;
		StripeSize = 0.4;
		StripeY = -1.2;
	}
}