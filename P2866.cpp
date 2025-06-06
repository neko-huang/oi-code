#include <iostream>

using namespace std;
const long long maxn = int(8e4 + 5);

long long C;
long long lg2[maxn];
long long st[maxn][30];
long long h[maxn];

long long read() {
	long long igt = 0, sgn = 1;
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

long long query(long long l, long long r) {
	long long tmp = lg2[r - l + 1];
	return max(st[l][tmp], st[r - (1 << tmp) + 1][tmp]);
}

signed main() {
	long long n = read();
	for (long long i = 1; i <= n; i++) {
		h[i] = read();
		st[i][0] = h[i];
	}
	for (long long i = 2; i <= n; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}
	for (long long i = 1; (1 << i) <= n; i++) {
		for (long long j = 1; j + (1 << i) - 1 <= n; j++) {
			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}	
	}
	for (long long i = 1; i <= n; i++) {
		long long l = i + 1, r = n;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (query(i + 1, mid) >= h[i]) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		C += (l - i - 1);
	}
	cout << C;
	return 0;
}