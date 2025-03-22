#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n; scanf("%d", &n);
	for (int m = 1; m <= n - 1; m++) {
		printf(" ");
		for (int i = 1; i < n + m - 1; i++) {
			if (i <= n - m -1) { printf(" "); continue; }
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i <= (n-1)*2+1; i++) { printf("*"); }
	printf("\n");
	for (int m = n-1; m >= 1; m--) {
		printf(" ");
		for (int i = 1; i < n + m - 1; i++) {
			if (i <= n - m - 1) { printf(" "); continue; }
			printf("*");
		}
		printf("\n");
	}
	return 0;
}