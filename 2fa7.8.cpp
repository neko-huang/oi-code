#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n,sum=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int o = i; o; o /= 10) {
			sum += (o % 10) * (o % 10) * (o % 10);
		}
		if (i == sum) {
			printf("%d\n", i);
		}
		sum = 0;
	}
	return 0;
}