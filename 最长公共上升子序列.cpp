#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = int(3e3 + 5);

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
	return igt*sgn;
}


int a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		b[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				for (int k = 1; k < i; k++) {
					if (a[k] < b[j]) {
						dp[i][j] = max(dp[i][j], dp[k][j] + 1);
					}
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][n];
	return 0;
}