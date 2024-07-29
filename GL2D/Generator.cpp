#include "Generator.h"
#include "Chocolate.h"

Generator::Generator() {
	// 다음 음식 생성 딜레이
	GenTime = 0.2;
	NextGenTime = 1;
}

void Generator::Update(float FT) {
	// 타이머 업데이트
	Timer.Update(FT);

	// 지정된 생성 시간에 도달하면 음식 생성 후 타이머 리셋
	if (Timer.MiliSec(2) >= NextGenTime) {
		GenerateFood();

		// 생성 시간에 약간의 랜덤 값을 부여한다
		RandomDelay = Rand.Gen(Dist::Real, -0.05, 0.05);
		NextGenTime = GenTime + RandomDelay;

		Timer.Reset();
	}
}

void Generator::GenerateFood() {
	fw.AddObject(new Chocolate, "chcolate", Layer::L3);
}