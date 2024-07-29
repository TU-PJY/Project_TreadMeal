#include "Generator.h"
#include "Chocolate.h"

Generator::Generator() {
	GenTime = 0.2;
}

void Generator::Update(float FT) {
	Timer.Update(FT);

	if (Timer.MiliSec(2) >= GenTime) {
		GenerateFood();
		Timer.Reset();
	}
}

void Generator::GenerateFood() {
	fw.AddObject(new Chocolate, "chcolate", Layer::L3);
}