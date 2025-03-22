#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n;i++) {
		for (int o = 1; o <= m; o++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}