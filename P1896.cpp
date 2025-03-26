#include <iostream>
using namespace std;
const int maxn = 9;
int dp[maxn + 1][1 << maxn][maxn*maxn+1];
int status[1 << maxn][2];
int cnt;
int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-'){
			sgn=-1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int main() {
	int n = read(), k = read();
	for (int i = 0; i < (1 << n); i++) {
		if (i & (i << 1)) {
			continue;
		}
		int tmp = 0;
		for (int j = i; j > 0; j = (j - 1) & i) {
			tmp++;
		}
		status[++cnt][0] = i;
		status[cnt][1] = tmp;
	}
	for (int i = 1; i <= cnt; i++) {
		dp[1][status[i][0][status[i][1]] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= cnt; j++) {
			for (int k = 1; k <= cnt; k++) {
				if (!dp[i - 1][k]) {
					continue;
				}
				if ((status[k][0]<<1) & status[j][0]) {
					continue;
				}
				if ((status[k][0] << 2) & status[j][0]) {
					continue;
				}
				for (int l = status[k][1]; l <= k; l++) {
					dp[i][status[j][0]][l] += dp[i - 1][status[k][0]][l-status[k][1]];
				}
			}
		}
	}
	//dui o
	//zhi you [k] ge guo wang
	long long ans = 0;
	for (int i = 1; i <= cnt; i++) {
		ans += dp[n][i][k];
	}
	printf("%d", ans);
}