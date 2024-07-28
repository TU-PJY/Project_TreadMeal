#include "Treadmil.h"

Treadmil::Treadmil() {
	SetImage(Body, "treadmil");
	SetImage(Stripe, "treadmil_prop");

	// �ʱ� �ӵ� 0.5
	MoveSpeed = 3;
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
		Move(StripeX + ((0.4 - StripeSize) * 0.2), StripeY);
		RenderImage(Stripe, 1.0, 100, 150);
	}

	else {
		Move(StripeX - ((0.4 - StripeSize) * 0.2), StripeY);
		RenderImage(Stripe, 1.0, 100, 150, Flip::Vertical);
	}

	EndColorClipping();
}

void Treadmil::Update(float FT) {
	// �־��� ������ ������Ʈ �̵�
	StripeX += cos(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeY += sin(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeSize -= MoveSpeed * 0.1 * FT;

	// ���̰� 0.3 �̻� �Ǹ� ���� ����� ��ġ�� �ݴ�� ��ȯ
	if (StripeY >= 0.3) {
		if (StripeDir == 1) {
			StripeX = -0.62;
			MoveDegree = 76.8;
		}

		else {
			StripeX = 0.62;
			MoveDegree = 103.2;
		}

		StripeDir *= -1;
		StripeSize = 0.4;
		StripeY = -1.2;
	}
}