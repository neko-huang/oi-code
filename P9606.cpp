#include <iostream>
#include <cstring>

using namespace std;
const int maxn = int(8e5 + 5);

int len[maxn];
char s[maxn], afs[maxn];
int tot;

int main() {
	int n;
	cin>>n;
	cin>>(s + 1);

	afs[0] = '!';
	afs[++tot] = '@';
	for (int i = 1; i <= n; i++) {
		afs[++tot] = s[i];
		afs[++tot] = '@';
	}
	
	int ans = 0;
	int l = 0, r = 1;
	for (int i = 2; i <= tot; i++) {
		if (r > i) {
			len[i] = min(len[r - len[i] + l], r - len[i] + 1);
		}
		while (afs[i - len[i]] == afs[i + len[i]]) {
			len[i]++;
		}
		if (r < i + len[i] - 1) {
			r = i + len[i] - 1;
			l = i - len[i] + 1;
		}
	}
	for (int i = 1; i <= tot; i++) {
		if (i + len[i] - 1==tot) {
			ans = max(len[i],ans);
		}
	}
	printf("%d", (tot+1)/2-ans);
	return 0;
}