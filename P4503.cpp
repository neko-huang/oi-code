#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = int(3e4 + 5);
const int maxl = int(205);

const int base1 = int(233);
const int base2 = int(193);
const int mod = int(1e9 + 9);

struct node {
	int h1, h2;
};
node has[2][maxl][maxn];
node tmphs[maxn];
bool cmp(node a, node b) {
	if (a.h1 != b.h1) {
		return a.h1 < b.h1;
	}
	else {
		return a.h2 < b.h2;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, l, s;
	cin >> n >> l >> s;
	string tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			has[0][j + 1][i].h1 = has[0][j][i].h1 * base1;
			has[0][j + 1][i].h1 += tmp[j] - '0' + 1;
			has[0][j + 1][i].h2 = has[0][j][i].h2 * base2;
			has[0][j + 1][i].h2 += tmp[j] - '0' + 1;
		}
		for (int j = tmp.length() - 1; j >= 0; j--) {
			has[1][j + 1][i].h1 = has[1][j + 2][i].h1 * base1;
			has[1][j + 1][i].h1 += tmp[j] - '0' + 1;
			has[1][j + 1][i].h2 = has[1][j + 2][i].h2 * base2;
			has[1][j + 1][i].h2 += tmp[j] - '0' + 1;
		}
	}
	int Ans = 0;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= n; j++) {
			tmphs[j].h1 = has[0][i - 1][j].h1 * base1 + has[1][i + 1][j].h1 * base2;
			tmphs[j].h2 = has[0][i - 1][j].h2 * base1 + has[1][i + 1][j].h2 * base2;
		}
		sort(tmphs + 1, tmphs + n + 1, cmp);
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (tmphs[i].h1 == tmphs[i + 1].h1 and tmphs[i].h2 == tmphs[i + 1].h2) {
				Ans += ans++;
			}
			else {
				ans = 1;
			}
		}
	}
	cout << Ans;
	return 0;
}