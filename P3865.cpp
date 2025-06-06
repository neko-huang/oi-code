#include <iostream>

using namespace std;
const int maxn = int(1e5 +5);

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c < '0' or c>'9') {
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

int lg2[maxn];
int st[maxn][30];
int a[maxn];

int main() {
	int n = read(),m=read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		st[i][0] = a[i];
	}
	for (int i = 2; i <= n; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j + (1 << i) -1 <= n; j++) {//2^n -1 
			st[j][i] = max(st[j][i - 1], st[j + (1 << i -1)][i - 1]);
		}
	}

	while (m--) {
		int l = read(), r = read();
		cout << max(st[l][lg2[r - l + 1]], st[r - (1 << lg2[r - l + 1]) + 1][lg2[r - l + 1]])<<'\n';
	}

	return 0;
}