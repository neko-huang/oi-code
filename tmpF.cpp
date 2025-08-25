#include <iostream>
#include <string.h>

using namespace std;

const int maxn = int(2e3 + 5);

int nxt[maxn];

void getnxt(string x) {
	for (int i = 1, j = 0; i < x.length(); i++ ) {
		if (j != 0 and x[j] != x[i]) {
			j = nxt[j - 1];
		}
		if (x[i] == x[j]) {
			nxt[i] = ++j;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string in;
		cin >> in;

		memset(nxt, 0, sizeof(nxt));
		int len = in.length();

		if (len % 2 or len < 4) {
			cout << '0';
		}
		int ans = 0;
		for (int i = 2; i < len; i+=2) {
			bool flag1 = 0, flag2 = 0;
			string l, r;
			l = in.substr(0, i);
			r = in.substr(i, len - i);
			getnxt(l);
			if (nxt[l.length() - 1] * 2 == l.length()) {
				flag1 = 1;
			}
			getnxt(r);
			if (nxt[r.length() - 1] * 2 == r.length()) {
				flag2 = 1;
			}
			if (flag1 and flag2) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}