#include <stdio.h>
using namespace std;
long long fbni[10000];
#pragma warning(disable:4996)
int main() {
	int n;
	scanf("%d", &n);
	fbni[0] = fbni[1] = 1;
	for (int i = 2; i <= n; i++) {
		fbni[i] = fbni[i - 1] + fbni[i - 2];
	}
	printf("%lld", fbni[n]);
}