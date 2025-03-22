#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int money=0,bank=0,cost=0;
	for (int i = 1; i <= 12; i++) {
		scanf("%d",&cost);
		cost -= money;
		money = 0;
		cost = 300 - cost;
		if (cost < 0) { printf("-%d", i); return 0; }
		bank += (cost / 100) * 100;
		money+=cost % 100;
	}
	bank *= 1.2;
	printf("%d", bank+ money);
	return 0;
}