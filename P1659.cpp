#include <iostream>
#include <cstring>

using namespace std;
const int maxn = int(1e6 + 5);
const int mod = 19930726;

int len[maxn];
char s[maxn];
int tot, ans=1;
int buc[maxn];

int fast_pow(int a, int n) {
	int base = a, ret = 1;
	//n >>= 1;
	while (n) {
		if (n & 1) {
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
	int n, k;
	cin >> n >> k;
	cin >> (s + 1);
	
	int l = 0, r = 1;
	s[0] = '!';
	len[1] = 1;
	for (int i = 2; i <= n; i++) {
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
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += (len[i]+1)/2;
		buc[len[i]]++;
	}
	if (k > cnt) {
		printf("-1");
		return 0;
	}
	for (int i = maxn-3; i > 1; i -= 2) {
		if (buc[i]) {
			ans = ans * pow(i,min(k,buc[i]));
			ans %= mod;
			k -= min(k, buc[i]);
			if (!k) {
				break;
			}
		}
	}
	printf("%d", ans);
}