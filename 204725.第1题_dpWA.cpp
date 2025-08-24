#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[22][100];
int S[22][100];

const int maxn = 20;
const int maxnum = 99;
long long sq10[20];
bool buc[10];

void init() {
	sq10[0] = 1;
	for (long long i = 1; i <= 19; i++) {
		sq10[i] = sq10[i - 1] * 10;
	}
}

void dis(long long x) {

	return;
}

long long len(long long x) {
	for (long long i = 0; i < 19; i++) {
		if (x >= sq10[i] and x < sq10[i + 1]) {
			return i + 1;
		}
	}
}

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
	init();
	memset(dp, 0x3f, sizeof(dp));
	int n = read(), x = read();
	if (x == 1 and n != 1) {
		cout << "-1";
		return 0;
	}
	int tmpx = x;
	while (tmpx >= 100) {
		tmpx /= 10;
	}
	int lenx = len(x);
	S[lenx][tmpx] = x;
	dp[lenx][tmpx] = 0;
	for (int i = lenx; i <= n; i++) {
		for (int j = (i == 1 ? 2 : 10); j <= maxnum; j++) {
			memset(buc, 0, sizeof(buc));
			int tmp = S[i][j];
			while (tmp) {
				buc[tmp%10] = 1;
				tmp /= 10;
			}
			for (int k = 2; k <= 9; k++) {
				if (buc[k]) {
					if (len(k * j) > len(j)) {
						dp[i + 1][(k * j >= 100 ? k * j / 10 : k * j)] = min(dp[i + 1][k * j / 10], dp[i][j] + 1);
						S[i + 1][(k * j>=100 ? k*j/10 : k*j)] = S[i][j] * k;
					}
					else {	
						dp[i][k * j] = min(dp[i][k * j], dp[i][j] + 1);
						S[i][k * j] = S[i][j] * k;
					}
				}
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 2; i <= 99; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout << ans;
}