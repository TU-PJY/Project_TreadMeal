#include "Chocolate.h"

Chocolate::Chocolate() {
	SetImage(InSide, "chocolate_inside");
	SetImage(OutSide, "chocolate_outside");

	int ColorSet = Rand.Gen(Dist::Int, 1, 6);
	switch (ColorSet) {
	case 1: // green
		R = 14; G = 128; B = 77;
		break;

	case 2: //orange
		R = 255; G = 137; B = 81;
		break;

	case 3:  // blue
		R = 21; G = 103; B = 183;
		break;

	case 4:  // brown
		R = 62; G = 40; B = 35;
		break;

	case 5:  // red
		R = 205; G = 33; B = 47;
		break;

	case 6:  // yellow
		R = 255; G = 200; B = 79;
		break;
	}

	Line = Rand.Gen(Dist::Int, 1, 5);

	switch (Line) {
	case 1:
		Position.x = FIRST_LINE_POSITION;
		MoveDegree = FIRST_LINE_DEGREE;
		break;
	case 2:
		Position.x = SECOND_LINE_POSITION;
		MoveDegree = SECOND_LINE_DEGREE;
		break;
	case 3:
		Position.x = THIRD_LINE_POSITION;
		MoveDegree = THIRD_LINE_DEGREE;
		break;
	case 4:
		Position.x = FOURTH_LINE_POSITION;
		MoveDegree = FOURTH_LINE_DEGREE;
		break;
	case 5:
		Position.x = FIFTH_LINE_POSITION;
		MoveDegree = FIFTH_LINE_DEGREE;
		break;
	}

	Position.y = -1.2;

	aabb.Init();
}

void Chocolate::Update(float FT) {
	if (auto treadmil = fw.Find("treadmil"); treadmil)
		MoveSpeed = treadmil->GetSpeed();

	if (!FallingState) {
		if (Position.x != 0.0)
			MoveForward(Position.x, Position.y, MoveSpeed, MoveDegree, FT);
		else
			MoveStraight(Position.x, MoveSpeed, FT);

		Size -= MoveSpeed * 0.05 * FT;

		if (Position.y - (0.2 - Size) >= -0.12) {
			fw.SwapLayer(this, Layer::L2);
			FallingState = true;
		}
	}
	
	else {
		Position.y -= 0.4 * FT;
		if (Position.y - (0.2 - Size) < - 0.2)
			fw.DeleteSelf(this);
	}

	if (Position.x < 0)
		aabb.Update(Position.x - (0.2 - Size) * 0.2, Position.y - (0.2 - Size), Size, Size * 0.8);
	else if(Position.x > 0)
		aabb.Update(Position.x + (0.2 - Size) * 0.2, Position.y - (0.2 - Size), Size, Size * 0.8);
	else
		aabb.Update(Position.x, Position.y - (0.2 - Size), Size, Size * 0.8);

	if (auto erpin = fw.Find("erpin"); erpin)
		if (!FallingState && aabb.CheckCollision(erpin->GetAABB()))
			fw.DeleteSelf(this);
}

void Chocolate::Render() {
	BeginProcess(ImageRenderMode::Default);

	if(Position.x < 0)
		Move(Position.x - (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else if(Position.x > 0)
		Move(Position.x + (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else
		Move(Position.x, Position.y - (0.2 - Size));

	Scale(Size, Size);

	SetColorRGB(R, G, B);
	RenderImage(InSide);

	SetColor(0.0, 0.0, 0.0);
	RenderImage(OutSide);


	aabb.BeginProcess();
	if (Position.x < 0)
		aabb.Move(Position.x - (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else if (Position.x > 0)
		aabb.Move(Position.x + (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else
		aabb.Move(Position.x, Position.y - (0.2 - Size));

	aabb.Scale(Size, Size * 0.8);
	aabb.Render(true);
}