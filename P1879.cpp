#include <iostream>
using namespace std;
const int maxn = 12;
const int mod = int(1e8);
int dp[maxn+1][1 << maxn+1];
int status[1<<maxn];
int cnt;
int line[maxn + 1];
int read() {
	int igt=0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
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
	int m = read(), n = read();
	for (int i = 1; i<=m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = read();
			if (tmp) {
				line[i] |= (1 << j);
			}
		}
	}
	//try try bianli
	for (int i = 0; i < (1 << maxn); i++) {
		if (i & (i << 1)) {
			continue;
		}
		status[++cnt] = i;
	}
	for (int i = 1; i <= cnt; i++) {
		if ((status[i] & line[1]) != status[i]) {
			continue;
		}
		dp[1][status[i]] = 1;
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= cnt; j++) {
			if ((status[j] & line[i]) != status[j]) {
				continue;
			}
			for (int k = 1; k <= cnt; k++) {
				if (!dp[i - 1][status[k]] or (status[j] & status[k])) {
					continue;
				}
				dp[i][status[j]] += dp[i-1][status[k]];
				dp[i][status[j]] %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		ans += dp[m][status[i]];
		ans %= mod;
	}
	printf("%d", ans);
	return 0;
}