#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int o = 1; o <= n; o++) {
			if (o <= i-1) {
				printf(" ");
				continue;
			}
			else {
				printf("*");
				continue;
			}
		}
		printf("\n");
	}
	return 0;
}