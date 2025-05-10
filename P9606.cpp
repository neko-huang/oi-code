#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const ll maxn = int(8e5 + 5);

ll len[maxn];
char s[maxn], afs[maxn];
ll tot;

int main() {
	ll n;
	cin>>n;
	cin>>(s + 1);

	afs[0] = '!';
	afs[++tot] = '@';
	for (ll i = 1; i <= n; i++) {
		afs[++tot] = s[i];
		afs[++tot] = '@';
	}
	
	ll ans = 0;
	ll l = 0, r = 1;
	len[1] = 1;
	for (ll i = 2; i <= tot; i++) {
		if (r >= i) {
			len[i] = min(len[r - i + l], r - i + 1);
		}
		while (afs[i - len[i]] == afs[i + len[i]]) {
			len[i]++;
		}
		if (r < i + len[i] - 1) {
			r = i + len[i] - 1;
			l = i - len[i] + 1;
		}
	}
	for (ll i = 1; i <= tot; i++) {
		if (i + len[i] - 1==tot) {
			ans = max(len[i],ans);
		}
	}
	printf("%lld", n-(ans-1));
	return 0;
}