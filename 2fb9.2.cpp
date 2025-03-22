#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
bool check(int a) {
	while (a != 0) {
		if (a % 10 == 4) { return 1; }
		a /= 10;
	}
	return 0;
}
int main() {
	int n, num = 1, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		while (num % 4 == 0 or check(num) == 1) {
			num++;
		}
		sum += num;
		num++;
	}
	printf("%d", sum);
}