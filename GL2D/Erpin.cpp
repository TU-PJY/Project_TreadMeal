#include "Erpin.h"
#include "MouseUtil.h"
#include <cmath>

Erpin::Erpin() {
	SetImage(Body, "erpin");
	SetImage(Wing, "erpin_wing");
	SetImage(NormalFace, "erpin_face_normal");
	SetImage(BlinkFace, "erpin_face_blink");
	SetImage(EatFace, "erpin_face_eat");

	aabb.Init();
}

AABB Erpin::GetAABB() {
	return aabb;
}

void Erpin::Update(float FT) {
	// 마우스가 움직이면 에르핀의 위치가 이동되고 회전한다
	Position += mouse.x * 0.25;
	Rotation += mouse.x * 10;

	// -0.4 ~ 0.4 사이에서만 이돟
	if (Position > 0.4)
		Position = 0.4;
	else if (Position < -0.4)
		Position = -0.4;

	// 회전 각도는 선형 보간 복귀
	Rotation = std::lerp(Rotation, 0.0, 20 * FT);

	// 날개의 x위치는 에르핀의 위치를 선형 보간으로 추적한다
	WingPosition.x = std::lerp(WingPosition.x, Position, 20 * FT);

	// 날개의 y위치는 상하 왕복 한다
	WingPosition.y = LSA_Wing.Update(0.05, FT * 2);

	// 눈 깜빡임 업데이트
	// 3초마다 눈을 깜빡인다
	BlinkTimer.Update(FT);
	if (!BlinkState && BlinkTimer.Sec() >= 3) {
		BlinkState = true;
		BlinkTimer.Reset();
	}

	// 눈 깜빡임 활성화 상태일 때는 0.2초후 눈 깜빡임을 비활성화 한다
	else if (BlinkState && BlinkTimer.MiliSec() >= 0.2) {
		BlinkState = false;
		BlinkTimer.Reset();
	}

	aabb.Update(Position, -0.12, 0.1, 0.05);
}

void Erpin::Render() {
	// 에르핀 날개
	BeginProcess(ImageRenderMode::Default);
	Move(WingPosition.x, 0.1 + WingPosition.y);
	Rotate(Rotation);
	Scale(1.5, 1.5);
	RenderImage(Wing, 1.0, 360, 256);

	// 에르핀 몸통
	BeginProcess(ImageRenderMode::Default);
	Move(Position , 0.1);
	Rotate(Rotation);
	Scale(1.5, 1.5);
	RenderImage(Body, 1.0, 360, 256);

	// 에르핀 얼굴
	// 상태에 따라 다른 이미지를 출력한다
	// 몸통 파트에서 행렬 계산을 끝냈으므로 해당 파츠는 행렬 계산을 하지 않고 바로 출력한다
	if (!EatState) {
		if (BlinkState)
			RenderImage(BlinkFace);
		else
			RenderImage(NormalFace);
	}
	else
		RenderImage(EatFace);

	aabb.BeginProcess();
	aabb.Move(Position, -0.12);
	aabb.Scale(0.1, 0.05);
	aabb.Render(true);
}