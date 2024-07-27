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
	BeginProcess(ImageRenderMode::Default);
	Move(0.0, -0.2);
	Scale(2.0, 2.0);
	RenderImage(Body, 1.0, 400, 350);

	SetColorClipping();
	BeginProcess(ImageRenderMode::Default);
	Scale(0.3, 0.3);
	Move(StripeX, StripeY);

	// 1이면 오른쪽방향, 0이면 왼쪽 방향에 렌더링
	if(StripeDir == 1)
		RenderImage(Stripe, 1.0, 50, 100);
	else
		RenderImage(Stripe, 1.0, 50, 100, Flip::Vertical);

	EndColorClipping();
}

void Treadmil::Update(float FT) {
	// 주어진 각도로 오브젝트 이동
	StripeX += cos(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeY += sin(glm::radians(MoveDegree)) * MoveSpeed * FT;

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

		StripeY = -1.2;
	}
}