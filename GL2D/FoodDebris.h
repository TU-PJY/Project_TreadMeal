#pragma once
#include "Framework.h"
#include <array>

class FoodDebris : public BASE {
private:
	Image Particle{}, OutSide{};
	glm::vec2 Position{};
	glm::vec3 DebrisColor{};

	GLfloat Rotation{};
	GLfloat Speed{};
	GLfloat FallingAcc{};

	RandomUtil Rand;
	PhysicsUtil PU;

	int R{}, G{}, B{};

public:
	FoodDebris(GLfloat Position, int r, int g, int b);
	void Update(float FT);
	void Render();
};