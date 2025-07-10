#include <iostream>

using namespace std;
const int maxn = int(1e5 + 5);

int l[maxn], r[maxn];

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

int main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	int n = read();
	for (int i = 0; i < n; i++) {
		l[i] = read();
		r[i] = read();
	}
	int ans = 0;
	for (int i = n - 1; i; i = r[i]) {
		ans++;
	}
	cout << min(ans, n - ans);
	return 0;
}