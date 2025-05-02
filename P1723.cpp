#include <iostream>
#include <cstring>

using namespace std;
const int maxn = int(2e7 + 5);

int len[maxn];
char s[maxn], afs[maxn];
int tot; int ans;

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		ans = 0; tot = 0;
		memset(afs, 0, sizeof(afs));
		memset(s, 0, sizeof(s));
		memset(len, 0, sizeof(len));

		scanf("%s", (s + 1));

		afs[0] = '!';
		afs[++tot] = '#';
		int tl = strlen(s+1);
		for (int i = 1; i <= tl; i++) {
			afs[++tot] = s[i];
			afs[++tot] = '#';
		}

		len[1] = 1;
		int l = 0, r = 1;
		for (int i = 2; i <= tot; i++) {
			if (r > i) {
				len[i] = min(len[l + r - i], r - i + 1);
			}
			while (afs[i - len[i]] == afs[i + len[i]]) {
				len[i]++;
			}
			if (r < i + len[i] + 1) {
				r = i + len[i] - 1;
				l = i - len[i] + 1;
			}
			ans = max(ans, len[i]);
		}

		printf("%d\n", ans - 1);
	}
}