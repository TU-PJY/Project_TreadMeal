#include "Treadmil.h"

Treadmil::Treadmil() {
	SetImage(Body, "treadmil");
	SetImage(Stripe, "treadmil_prop");

	// 초기 속도 0.5
	MoveSpeed = 0.5;
}

void Treadmil::Render() {
	// 트레드밀 위에 줄 오브젝트를 컬러 클리핑 한다
	BeginColorClipping();

	// 트레드밀
	BeginProcess(ImageRenderMode::Default);
	Move(0.0, -0.2);
	Scale(2.0, 2.0);
	RenderImage(Body, 1.0, 400, 350);

	SetColorClipping();

	// 줄 오브젝트
	// 위로 이동할 수록 크기가 점차 작아지고 작아진 수치 만큼 x축으로 이동한다
	// 1이면 오른쪽방향, 0이면 왼쪽 방향에 렌더링
	BeginProcess(ImageRenderMode::Default);
	Scale(StripeSize, StripeSize);

	if (StripeDir == 1) {
		Move(StripeX + ((0.3 - StripeSize) * 0.2), StripeY);
		RenderImage(Stripe, 1.0, 50, 100);
	}

	else {
		Move(StripeX - ((0.3 - StripeSize) * 0.2), StripeY);
		RenderImage(Stripe, 1.0, 50, 100, Flip::Vertical);
	}

	EndColorClipping();
}

void Treadmil::Update(float FT) {
	// 주어진 각도로 오브젝트 이동
	StripeX += cos(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeY += sin(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeSize -= MoveSpeed * 0.1 * FT;

	// 높이가 0.3 이상 되면 줄의 방향과 위치를 반대로 전환
	if (StripeY >= 0.3) {
		if (StripeDir == 1) {
			StripeX = -0.62;
			MoveDegree = 76.8;
			StripeDir = 0;
		}

		else {
			StripeX = 0.62;
			MoveDegree = 103.2;
			StripeDir = 1;
		}

		StripeSize = 0.3;
		StripeY = -1.2;
	}
}