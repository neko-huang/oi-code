#include <iostream>
#include <cstring>

using namespace std;
const long long maxn = int(1.1e7 + 5);

char sr[maxn];
char s[maxn * 2];
long long len[maxn * 2];

signed main() {
	cin >> sr;
	long long cnt = 0;
	s[0] = '$';
	long long srlen = strlen(sr);
	for (long long i = 0; i < srlen; i++) {
		s[++cnt] = '#';
		s[++cnt] = sr[i];
	}
	s[++cnt] = '#';
	long long ans = 0;
	len[1] = 1;
	for (long long l = 0, r = 1, i = 2; i <= cnt; i++) {
		if (i <= r) {
			len[i] = min(len[l + r - i], r - i + 1);
		}
		while (s[i - len[i]] == s[i + len[i]]) {
			len[i]++;
		}
		if (i + len[i] - 1 > r) {
			l = i - len[i] + 1;
			r = i + len[i] - 1;
		}
		ans = max(ans, len[i]);
	}

	cout << ans - 1;
	return 0;
}