#include <iostream>
using namespace std;

const int maxn = int(1e3 + 5);

int a[maxn];
int dp[maxn][maxn];//i ge ren j zu

int read() {
	int igt = 0, sgn = 1;
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
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + a[k]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}