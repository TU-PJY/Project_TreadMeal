#include "Erpin.h"
#include "MouseUtil.h"
#include <cmath>

Erpin::Erpin() {
	SetImage(Body, "erpin");
	SetImage(Wing, "erpin_wing");
	SetImage(NormalFace, "erpin_face_normal");
	SetImage(EatFace, "erpin_face_eat");
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

	// 날개는 에르핀의 위치를 선형 보간으로 추적한다
	WingPosition = std::lerp(WingPosition, Position, 20 * FT);
}

void Erpin::Render() {
	// 에르핀 날개
	BeginProcess(ImageRenderMode::Default);
	Move(WingPosition, 0.1);
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
	if (!EatState)
		RenderImage(NormalFace);
	else
		RenderImage(EatFace);
}