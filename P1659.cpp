#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const ll maxn = int(1e6 + 5);
const ll mod = 19930726;

ll len[maxn];
char s[maxn];
ll tot, ans=1;
ll buc[maxn];

ll fast_pow(ll a, ll n) {
	ll base = a, ret = 1;
	while (n) {
		if (n % 2) {
			ret = ret * base;
			ret %= mod;
		}
		base = base * base;
		base %= mod;
		n >>= 1;
	}
	return ret % mod;
}

int main() {
	ll n, k;
	cin >> n >> k;
	cin >> (s + 1);
	
	ll l = 0, r = 1;
	s[0] = '!';
	len[1] = 1;
	for (ll i = 2; i <= n; i++) {
		if (r >= i) {
			len[i] = min(len[l + r - i], r - i + 1);
		}
		while (s[i - len[i]] == s[i + len[i]]) {
			len[i]++;
		}
		if (r < i + len[i] - 1) {
			r = i + len[i] - 1;
			l = i - len[i] + 1;
		}
	}
	ll cnt = 0; ll tm = 0;
	for (ll i = 1; i <= n; i++) {
		cnt += len[i];
		buc[len[i]]++;
		tm = max(tm, len[i]);
	}
	if (k > cnt) {
		printf("-1");
		return 0;
	}
	for (ll i = tm; i > 1; i--) {
		if (buc[i]) {
			ans = ans * fast_pow(i*2-1,min(k,buc[i]));
			ans %= mod;
			buc[i-1] += min(k, buc[i]);
			k -= min(k, buc[i]);
			buc[i] -= min(k, buc[i]);
			if (!k) {
				break;
			}
		}
	}
	printf("%lld", ans);
}