#pragma once
#include "Framework.h"

class Erpin : public BASE {
private:
	Image Body{}, Wing{}, NormalFace{}, EatFace{};
	GLfloat Position{};
	GLfloat WingPosition{};
	GLfloat Rotation{};

	// Ʈ����� ������ �����̴� ������ �Ծ��� �� Ȱ��ȭ
	bool EatState{};

public:
	Erpin();
	void Update(float FT);
	void Render();
};

