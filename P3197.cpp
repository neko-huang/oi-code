#include <iostream>
using namespace std;

const long long mod = int(1e5 + 3);

long long pow2(long long a,long long x) {
	long long base = a, ret = 1;
	while (x) {
		if (x & 1) {
			ret *= base;
			ret %= mod;
		}
		base *= base;
		base %= mod;
		x >>= 1;
	}
	return ret;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long m, n; cin >> m >> n;
	long long ans = pow2(m, n % (mod - 1));
	ans %= mod;
	ans -= m*pow2(m - 1, (n - 1) % (mod - 1));	
	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans;
	return 0;
}