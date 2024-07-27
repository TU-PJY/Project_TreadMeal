#include "Treadmil.h"

Treadmil::Treadmil() {
	SetImage(Body, "treadmil");
	SetImage(Stripe, "treadmil_prop");
	MoveSpeed = 0.5;
}

void Treadmil::Render() {
	BeginColorClipping();
	BeginProcess(ImageRenderMode::Default);
	Move(0.0, -0.2);
	Scale(2.0, 2.0);
	RenderImage(Body, 1.0, 400, 350);

	SetColorClipping();
	BeginProcess(ImageRenderMode::Default);
	Scale(0.3, 0.3);
	Move(StripeX, StripeY);
	if(StripeDir == 1)
		RenderImage(Stripe, 1.0, 50, 100);
	else
		RenderImage(Stripe, 1.0, 50, 100, Flip::Vertical);

	EndColorClipping();
}

void Treadmil::Update(float FT) {
	StripeX += cos(glm::radians(MoveDegree)) * MoveSpeed * FT;
	StripeY += sin(glm::radians(MoveDegree)) * MoveSpeed * FT;

	if (StripeY >= 0.3) {
		if (StripeDir == 1) {
			StripeX = -0.64;
			MoveDegree = 77;
			StripeDir = 0;
		}

		else {
			StripeX = 0.64;
			MoveDegree = 103;
			StripeDir = 1;
		}

		StripeY = -1.2;
	}
}