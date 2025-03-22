#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
bool prime(int a) {
	for (int i = 2; i < a / i; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
bool yin(int a, int b) {
	if (a % b == 0) {
		return 1;
	}
	return 0;
}
int main() {
	int n; scanf("%d",&n);
	for (int i = 2; n != 1; i++) {
		if (prime(i) == 1) {
			while (yin(n,i) == 1) {
				printf("%d", i);n /= i;
				if (n != 1) {
					printf("*");
				}
			}
		}
	}
	return 0;
}