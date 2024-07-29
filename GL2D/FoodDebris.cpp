#include "FoodDebris.h"

FoodDebris::FoodDebris(GLfloat X, int r, int g, int b) {
	SetImage(Particle, "debris");

	// ��� ��ƼŬ�� ��ġ�� ���ݾ� �ٸ��� �Ѵ�
	Position.x = Rand.Gen(Dist::Real, X - 0.05, X + 0.05);
	Position.y = Rand.Gen(Dist::Real, -0.1 - 0.05, -0.1 + 0.05);

	// �߶� ���ӵ��� �����ϰ� �����Ѵ�
	FallingAcc = Rand.Gen(Dist::Real, 0.4, 1.0);
	PU.AddGravityAcc(FallingAcc);

	// �¿� �̵� �ӵ��� �����ϰ� �����Ѵ�
	Speed = Rand.Gen(Dist::Real, -0.1, 0.5);

	// �������� ���� ������ ����� ������ ���� ����
	R = r;
	G = g;
	B = b;
}

void FoodDebris::Update(float FT) {
	// ��ƼŬ�� ���� �������� �������� ������
	PU.Fall(Position.y, 2.0, FT);
	TransparencyValue -= FT;

	if (TransparencyValue < 0) {
		TransparencyValue = 0;
		fw.DeleteSelf(this);
	}

	// ���� �Ǵ� ���������� �̵��Ѵ�
	MoveStraight(Position.x, Speed, FT);
}

void FoodDebris::Render() {
	// ��ƼŬ ������
	BeginProcess(ImageRenderMode::Default);
	Move(Position.x, Position.y);
	Scale(0.05, 0.05);

	SetColorRGB(R, G, B);
	RenderImage(Particle, TransparencyValue);
}