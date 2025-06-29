#include <iostream>

using namespace std;
const int maxn = int(1e6 + 5);

int	a[maxn];

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
	int n = read(), q = read();
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int now = 0;
	for (int i = 1; i <= q; i++) {
		int opt = read();
		if (opt == 1) {
			int p = read(), x = read();
			a[(p + now - 1 + n) % n] = x;
		}
		else if (opt == 2) {
			int p = read();
			cout << a[(p + now -1 +n) % n]<<'\n';
		}
		else {
			int k = read();
			now += k;
			now %= n;
		}
	}
	return 0;
}