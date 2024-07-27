#pragma once
#include "Framework.h"

class Treadmil : public BASE {
private:
	Image Body{}, Stripe{};

	GLfloat StripeX = 0.65, StripeY = -1.2;
	GLfloat MoveDegree = 103;
	int StripeDir = 1;  // 1:right, 0:left

	GLfloat MoveSpeed{};
	
public:
	Treadmil();
	void Render();
	void Update(float FT);
};