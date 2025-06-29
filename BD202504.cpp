#include <iostream>

using namespace std;
typedef unsigned long long ll;

ll read() {
	ll igt = 0, sgn = 1;
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

signed main() {
	ll t = read();
	while (t--) {
		ll l = read(), r = read();
		if (l == r) {
			printf("infty\n");
			continue;
		}
		ll ret = r - l;
		ll n = (l - 1) / ret;
		n++;
		ll fir = (l - 1) % ret;
		ll sec = (l - 1);
		ll ans = (fir + sec) * n / 2;
		printf("%lld\n", ans);
	}
	return 0;
}