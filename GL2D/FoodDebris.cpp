#include "FoodDebris.h"

FoodDebris::FoodDebris(GLfloat X, int r, int g, int b) {
	SetImage(Particle, "debris");

	Position.x = Rand.Gen(Dist::Real, X - 0.05, X + 0.05);
	Position.y = Rand.Gen(Dist::Real, -0.1 - 0.05, -0.1 + 0.05);

	FallingAcc = Rand.Gen(Dist::Real, 0.4, 1.0);
	PU.AddGravityAcc(FallingAcc);

	Speed = Rand.Gen(Dist::Real, -0.1, 0.5);

	R = r;
	G = g;
	B = b;
}

void FoodDebris::Update(float FT) {
	Rotation += FT * 400;
	PU.Fall(Position.y, 2.0, FT);

	if (Position.y < -0.2)
		fw.DeleteSelf(this);

	MoveStraight(Position.x, Speed, FT);
}

void FoodDebris::Render() {
	BeginProcess(ImageRenderMode::Default);
	Move(Position.x, Position.y);
	Rotate(Rotation);
	Scale(0.05, 0.05);

	SetColorRGB(R, G, B);
	RenderImage(Particle);
}