#pragma once
#include "Framework.h"

class Treadmil : public BASE {
private:
	Image Body{}, Stripe{};

	GLfloat StripeX = 0.62, StripeY = -1.2;
	GLfloat MoveDegree = 102.9;
	GLfloat StripeSize = 0.3;
	int StripeDir = 1;  // 1:right, -1:left

	GLfloat MoveSpeed{};
	
public:
	Treadmil();
	GLfloat GetSpeed();
	void Render();
	void Update(float FT);
};