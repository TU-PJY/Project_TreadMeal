#include "Generator.h"
#include "Chocolate.h"

Generator::Generator() {
	// ���� ���� ���� ������
	GenTime = 0.2;
	NextGenTime = 1;
}

void Generator::Update(float FT) {
	// Ÿ�̸� ������Ʈ
	Timer.Update(FT);

	// ������ ���� �ð��� �����ϸ� ���� ���� �� Ÿ�̸� ����
	if (Timer.MiliSec(2) >= NextGenTime) {
		GenerateFood();

		// ���� �ð��� �ణ�� ���� ���� �ο��Ѵ�
		RandomDelay = Rand.Gen(Dist::Real, -0.05, 0.05);
		NextGenTime = GenTime + RandomDelay;

		Timer.Reset();
	}
}

void Generator::GenerateFood() {
	fw.AddObject(new Chocolate, "chcolate", Layer::L3);
}