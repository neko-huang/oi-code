#include <iostream>

using namespace std;
typedef long long ll;

const ll maxn = ll(1e3 + 5);
ll map[maxn][maxn];
ll sum[maxn][maxn];

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
int main() {
	ll n=read(),m=read(),c=read();
	c--;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = read();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
		}
	}
	ll ans = 0; ll ansx, ansy;
	for (int i = 1; i + c <= n; i++) {
		for (int j = 1; j + c <= m; j++) {
			ll tmp = sum[i + c][j + c] - sum[i - 1][j + c] - sum[i + c][j - 1] + sum[i - 1][j - 1];
			if (tmp > ans) {
				ans = tmp;
				ansx = i;
				ansy = j;
			}
		}
	}
	cout << ansx << ' ' << ansy;
	return 0;
}