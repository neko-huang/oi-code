#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double sum = 0;
	sum += a * (a + 1) / 2.0;
	sum += b * (b + 1) * (2 * b + 1) / 6.0;
	for (int i = 1; i <= c; i++) {
		sum += 1.0 / i;
	}
	printf("%.2lf", sum);
	return 0;
}