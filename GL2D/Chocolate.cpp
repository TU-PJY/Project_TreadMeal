#include "Chocolate.h"
#include "FoodDebris.h"

Chocolate::Chocolate() {
	SetImage(InSide, "chocolate_inside");
	SetImage(OutSide, "chocolate_outside");

	// 색상과 위치는 랜덤 지정
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

	//y위치는 모든 오브젝트가 동일
	Position.y = -1.2;
	aabb.Init();

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
}

void Chocolate::Update(float FT) {
	// 트레드밀의 속도와 동일한 속도로 움직인다
	if (auto treadmil = fw.Find("treadmil"); treadmil)
		MoveSpeed = treadmil->GetSpeed();

	if (!FallingState) {
		// x위치가 가운데가 아닌 경우 지정된 각도로 움직이고, 가운데일 경우 직진한다
		if (Position.x != 0.0)
			MoveForward(Position.x, Position.y, MoveSpeed, MoveDegree, FT);
		else
			MoveStraight(Position.x, MoveSpeed, FT);

		// 끝 부분으로 갈 수록 크기가 점차 작아진다
		Size -= MoveSpeed * 0.05 * FT;

		// 트레드밀 끝 부분에 도달하면 하위레이어로 이동 후 떨어진다
		if (Position.y - (0.2 - Size) >= -0.12) {
			fw.SwapLayer(this, Layer::L2);
			FallingState = true;
		}
	}
	
	// 떨어지다가 특정 위치에 도달하면 스스로 삭제
	else {
		Position.y -= 0.4 * FT;
		if (Position.y - (0.2 - Size) < - 0.2)
			fw.DeleteSelf(this);
	}

	// 위치에 따라 aabb업데이트를 다르게 한다
	if (Position.x < 0)
		aabb.Update(Position.x - (0.2 - Size) * 0.2, Position.y - (0.2 - Size), Size, Size * 0.8);
	else if(Position.x > 0)
		aabb.Update(Position.x + (0.2 - Size) * 0.2, Position.y - (0.2 - Size), Size, Size * 0.8);
	else
		aabb.Update(Position.x, Position.y - (0.2 - Size), Size, Size * 0.8);

	// 에르핀이 먹으면 바로 삭제한다
	if (auto erpin = fw.Find("erpin"); erpin)

		// aabb 충돌처리
		if (!FallingState && aabb.CheckCollision(erpin->GetAABB())) {
			// 에르핀 EatState 활성화
			erpin->SetEatState();

			// 음식 파티클 추가
			for (int i = 0; i < 4; ++i) {
				if (Position.x < 0)
					fw.AddObject(new FoodDebris(Position.x - (0.2 - Size) * 0.2, R, G, B), "food_debris", Layer::L2);
				else if (Position.x > 0)
					fw.AddObject(new FoodDebris(Position.x + (0.2 - Size) * 0.2, R, G, B), "food_debris", Layer::L2);
				if (Position.x < 0)
					fw.AddObject(new FoodDebris(Position.x, R, G, B), "food_debris", Layer::L2);
			}

			fw.DeleteSelf(this);
		}
}

void Chocolate::Render() {
	// 초콜릿 렌더링
	BeginProcess(ImageRenderMode::Default);

	// 사이즈가 작아진 만큼 위치를 이동시킨다
	if(Position.x < 0)
		Move(Position.x - (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else if(Position.x > 0)
		Move(Position.x + (0.2 - Size) * 0.2, Position.y - (0.2 - Size));
	else
		Move(Position.x, Position.y - (0.2 - Size));

	Scale(Size, Size);

	// 내부 컬러는 지정된 컬러로 렌더링하고, 외부 라인은 원본을 렌더링한다
	SetColorRGB(R, G, B);
	RenderImage(InSide);

	SetColor(0.0, 0.0, 0.0);
	RenderImage(OutSide);

	// aabb 바운드박스 렌더링
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