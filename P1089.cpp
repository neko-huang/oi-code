#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int mou[15] = {0},fmou[15]={0}, bank = 0, hand = 0;
	for (int i = 1; i <= 12; i++) {
		cin>>mou[i];
		fmou[i] = 300 - mou[i];
	}
	for (int i = 1; i <= 12; i++) {
		if (fmou[i] < 0) {
			if (fmou[i] + hand < 0) {
				printf("-%d", i);
				return 0;
			}
			else {
				hand += fmou[i];
				fmou[i] = 0;
				continue;
			}
		}
		else {
			bank += fmou[i] - fmou[i] % 100;
			fmou[i] = fmou[i] % 100;
			hand += fmou[i];
		}
	}
	bank *= 1.2;
	printf("%d", bank+hand);
	return 0;
}