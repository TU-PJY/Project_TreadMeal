#pragma once
#include "Framework.h"

class Generator : public BASE {
private:
	TimerUtil Timer;
	RandomUtil Rand;
	GLfloat GenTime{};
	GLfloat NextGenTime{};
	GLfloat RandomDelay{};

public:
	Generator();
	void Update(float FT);
	void GenerateFood();
};

