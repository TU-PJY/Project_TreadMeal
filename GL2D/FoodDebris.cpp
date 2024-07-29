#include "FoodDebris.h"

FoodDebris::FoodDebris(GLfloat X, int r, int g, int b) {
	SetImage(Particle, "debris");

	// 모든 파티클의 위치를 조금씩 다르게 한다
	Position.x = Rand.Gen(Dist::Real, X - 0.05, X + 0.05);
	Position.y = Rand.Gen(Dist::Real, -0.1 - 0.05, -0.1 + 0.05);

	// 추락 가속도를 랜덤하게 설정한다
	FallingAcc = Rand.Gen(Dist::Real, 0.4, 1.0);
	PU.AddGravityAcc(FallingAcc);

	// 좌우 이동 속도를 랜덤하게 설정한다
	Speed = Rand.Gen(Dist::Real, -0.1, 0.5);

	// 에르핀이 먹은 음식의 색상과 동일한 색상 적용
	R = r;
	G = g;
	B = b;
}

void FoodDebris::Update(float FT) {
	// 파티클은 생성 순간부터 떨어지기 시작함
	PU.Fall(Position.y, 2.0, FT);
	TransparencyValue -= FT;

	if (TransparencyValue < 0) {
		TransparencyValue = 0;
		fw.DeleteSelf(this);
	}

	// 왼쪽 또는 오른쪽으로 이동한다
	MoveStraight(Position.x, Speed, FT);
}

void FoodDebris::Render() {
	// 파티클 랜더링
	BeginProcess(ImageRenderMode::Default);
	Move(Position.x, Position.y);
	Scale(0.05, 0.05);

	SetColorRGB(R, G, B);
	RenderImage(Particle, TransparencyValue);
}