#pragma once
#include "Framework.h"

class Chocolate : public BASE {
private:
	Image InSide{}, OutSide{};
	glm::vec2 Position{};
	GLfloat MoveDegree{};
	GLfloat MoveSpeed{};
	GLfloat Size = 0.2;

	int Line = 1;
	int ColorSet{};
	int R{}, G{}, B{};
	RandomUtil Rand;

	bool FallingState{};

	AABB aabb;

public:
	Chocolate();
	void Update(float FT);
	void Render();

};

