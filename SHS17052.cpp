#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll pow2(ll a, ll x) {
	ll base = a, ret = 1;
	while (x) {
		if (x & 1) {
			ret *= base;
			ret %= mod;
		}
		base *= base;
		base %= mod;
		x >>= 1;
	}
	return ret % mod;
}
signed main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		m--;
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			ans += pow2(i, m);
			ans %= mod;
		}
		cout << ans % mod << '\n';
	}
	
	return 0;
}