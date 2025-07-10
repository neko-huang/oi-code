#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = int(1e5 + 5);

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

int a[maxn];

inline int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int ans = 0;
	bool flag = 1;
	for (; flag;) {
		int l = 0, r = 1;
		while (l <= n and not(a[l + 1] != 0 and a[l] == 0)) {
			l++;
		}
		while (r <= n and not(a[r - 1] != 0 and a[r] == 0)) {
			r++;
		}
		if (l > n and r > n) {
			flag = 0;
			continue;
		}
		int maxx = 0x3f3f3f3f;
		for (int i = l + 1; i < r; i++) {
			maxx = min(maxx, a[i]);
		}
		for (int i = l + 1; i < r; i++) {
			a[i] -= maxx;
		}
		ans += maxx;
	}
	cout << ans;
	return 0;
}