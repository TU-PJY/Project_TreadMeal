#pragma once
#include "Framework.h"

class Generator : public BASE {
private:
	TimerUtil Timer;
	GLfloat GenTime{};

public:
	Generator();
	void Update(float FT);
	void GenerateFood();
};

