#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int n; long long temp,max=-2147483647;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &temp);
		if (temp > max) { max = temp; }
	}
	printf("%lld", max);
	return 0;
}