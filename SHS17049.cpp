#include <iostream>
using namespace std;
typedef long long ll;

ll read() {
	ll igt = 0, sgn = 1;
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

const ll maxn = ll(1e3 + 5);
ll maze[maxn][maxn];
ll sum[maxn][maxn];

int main() {
	ll n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			maze[i][j] = read();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			maze[i][j] *= read();
		}
	}
	ll p = read(), q = read();
	p--; q--;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + maze[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i + p <= n; i++) {
		for (int j = 1; j + q <= m; j++) {
			ll tmp = sum[i + p][j + q] - sum[i - 1][j + p] - sum[i + p][j - 1] + sum[i - 1][j - 1];
			ans = max(ans, tmp);
		}
	}
	cout << ans;
	return 0;
}