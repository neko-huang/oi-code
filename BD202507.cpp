#include <iostream>

using namespace std;

typedef long long ll;
const int maxn = int(2e5 + 5);

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}

bool cmp(int a, int b) {
	return a <= b;
}
int dp[maxn];
int a[maxn];
int main() {
	int t = read();
	while (t--) {
		int n = read(), s = read();
		dp[0] = s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i] = s;
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = max((dp[i - 1] + a[i] + 1) / 2 , dp[i]);
			dp[i] = max(dp[i - 1], dp[i]);
		}
		cout << dp[n]<<'\n';
	}
	return 0;
}