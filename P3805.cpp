#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;
const int maxn = int(1.1e7 + 6);
char s[maxn * 2];
char crr[maxn];
int len[maxn * 2];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> crr;
	s[0] = '$';
	int cnt = 0,crrlen=strlen(crr);
	for (int i = 0; i < crrlen; i++) {
		s[i * 2 + 1] = '#'; s[i * 2 + 2] = crr[i];
		cnt = i * 2 + 2;
	}
	s[++cnt] = '#'; 

	int ans = 0;
	len[1] = 1;
	for (int l = 0, r = 1, i = 2; i <= cnt; i++) {
		if (i <= r) {
			len[i] = min(len[l + r - i], r - i + 1);
		}
		while (s[i - len[i]] == s[i + len[i]]) {
			len[i]++;
		}
		if (i + len[i] -1 > r) {
			r = i + len[i] - 1;
			l = i - len[i] + 1;
		}
		ans = max(ans, len[i]);
	}
	cout << ans - 1;
	return 0;
}