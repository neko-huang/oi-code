#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;const ll maxn = ll(3e5 + 5);

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
ll d[maxn];
ll cnt[maxn];
int main() {
	ll n=read(), l=read();
	if (l % 3) {
		cout << '0';
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		d[i] = read();
		d[i] += d[i - 1];
		d[i] %= l;
		cnt[d[i]]++;
	}
	cnt[0]++;
	l /= 3;
	ll ans=0;
	for (int i = 0; i < l; i++) {
		ans += cnt[i] * cnt[i + l] * cnt[i + 2 * l];
	}
	cout << ans;
	return 0;
}