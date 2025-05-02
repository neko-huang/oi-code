#include <iostream>
#include <cstring>

using namespace std;
const int maxn = int(1e5 + 5);

int len[maxn];
char s[maxn], afs[maxn << 1];
int tot, ans;

int main() {

	cin >> (s + 1);
	
	int tmp = strlen(s + 1);
	afs[0] = '!';
	afs[++tot] = '@';
	for (int i = 1; i <= tmp; i++) {
		afs[++tot] = s[i];
		afs[++tot] = '@';
	}

	int l = 0, r = 1;
	len[1] = 1;
	for (int i = 2; i <= tot; i++) {
		if (r > i) {
			len[i] = min(len[l + r - i], r - i + 1);
		}
		while (i - len[i] == i + len[i]) {
			len[i]++;
		}
		if (r < i - len[i] + 1) {
			r = i - len[i] + 1;
			l = i + len[i] - 1;
		}
	}


}