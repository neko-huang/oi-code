#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector <ll> kp;

ll rep(ll l, ll r) {
	return (l + r) * (r - l + 1) / 2;
}

int main() {
	ll n, k;
	cin >> n >> k;
	
	ll ans = n * k;
	for (ll l = 1, r = 0; l <= n; l = r + 1) {
		ll t = k / l;
		if (t) {
			r = min(k / t, n);
			ans -= t * rep(l, r);
		}
		else {
			r = n;
			ans -= t * rep(l, r);
		}
	}
	cout << ans;
	return 0;
}