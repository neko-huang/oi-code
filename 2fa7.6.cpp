#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int m, n, mon[25][25] = { 0 };
	scanf("%d%d",& m,& n);
	for (int i = 1; i <= m; i++) {
		for (int o = 1; o <= n; o++) {
			scanf("%d", &mon[i][o]);
		}
	}
	for (int o = 1; o <= m; o++) {
		for (int i = 1; i <= n; i++) {
			if (mon[o - 1][i] <= mon[o][i] and mon[o + 1][i] <= mon[o][i] and mon[o][i + 1] <= mon[o][i] and mon[o][i - 1] <= mon[o][i]) {
				printf("%d %d\n", o - 1, i - 1);
			}
		}
	}
}