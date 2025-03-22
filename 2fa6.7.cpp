#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int fbni[25],n;
	scanf("%d", &n);
	fbni[1] = 1; fbni[2] = 1;
	for (int i = 3; i <= n; i++) {
		fbni[i] = fbni[i - 1] + fbni[i - 2];
	}
	printf("%d", fbni[n]);
	return 0;
}