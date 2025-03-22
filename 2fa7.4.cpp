#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int m, n,f[1005],g[1005],small=2147483647;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &g[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int o = 1; o <= n; o++) {
			if (f[i] < g[o]) {
				if (g[o] - f[i] < small) {
					small = g[o] - f[i];
				}
			}
			else if (f[i] > g[o]) {
				if (f[i] - g[o] < small) {
					small = f[i] - g[o];
				}
			}
			else {
				printf("0");
				return 0;
			}
		}
	}
	printf("%d", small);
	return 0;
}