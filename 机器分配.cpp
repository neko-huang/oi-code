#include <iostream>
using namespace std;
int dp[20], f1[15][20];
int awa[15][20];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int o = 1; o <= m; o++) {
			cin >> awa[i][o];
		}
	}
	for (int i = n; i > 0; i--) {
		for (int o = m; o >= 0; o--) {
			for (int k = 1; k <= o; k++) {
				if (dp[o - k] + awa[i][k] > dp[o]) {
					dp[o] = dp[o - k] + awa[i][k];
					f1[i][o] = k;
				}
			}
		}
	}
	cout << dp[m];
	for (int i = 1,m1=m; i <= n; i++) {
		cout << endl<< i <<' '<< f1[i][m1] ;
		m1 -= f1[i][m1];
	}
}