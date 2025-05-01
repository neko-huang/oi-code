#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = ll(1e9 + 7);
const ll base = 31;
const ll maxn = ll(5e5 + 5);

ll tpow[maxn], lt_hash[maxn], rv_hash[maxn];
char lt_s[maxn],rv_s[maxn];
ll ans;

ll md(ll n) {
	return n % mod;
}

void backwards(ll x,ll n) {//dui cheng zhong xin
	ll l = 0, r = min(x, n - x);//tuo zhan chang du!
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (md(md(lt_hash[x] - lt_hash[x - mid] * tpow[mid]) + mod) == md(md(rv_hash[x + 1] - rv_hash[x + mid + 1] * tpow[mid])+mod)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	ans += l;
}

int main() {
	ll n;
	cin >> n;
	cin >> (lt_s + 1);
	tpow[0] = 1;
	for (ll i = 1; i <= n; i++) {
		tpow[i] = md(base * tpow[i-1]);
		rv_s[i] = (lt_s[i] == '0' ? '1':'0');
	}
	for (ll i = 1; i <= n; i++) {
		lt_hash[i] = md(lt_hash[i-1] * base + lt_s[i]+mod);
		rv_hash[n - i + 1] = md(rv_hash[n - i + 2] * base + rv_s[n-i+1]+mod);
	}
	for (ll i = 1; i <= n; i++) {
		backwards(i,n);
	}
	printf("%lld", ans);
	return 0;
}