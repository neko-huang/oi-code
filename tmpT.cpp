#include <iostream>

using namespace std;
const int maxn = int(1005);

int dp[maxn][maxn];
int eat[maxn][maxn];

int main() {
	freopen("input.txt", "r", stdin);


	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, h, delta;
	cin >> n >> h >> delta;
	for (int i = 1; i <= n; i++) {
		int cnt; cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			int tmp;
			cin >> tmp;
			eat[i][tmp]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i][h] = eat[i][h];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = h-1; j >= 0; j--) {
			dp[i][j] = max(dp[i][j], dp[i][j + 1] + eat[i][j]);
			for (int k = 1; k <= n; k++) {
				if (k != i) {
					dp[i][j] = max(dp[i][j], dp[k][j + delta] + eat[i][j]);
				}
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = h - 1; j >= 0; j--) {
			dp[i][j] = max(dp[i][j], dp[i][j + 1] + eat[i][j]);
			for (int k = 1; k <= n; k++) {
				if (k != i) {
					dp[i][j] = max(dp[i][j], dp[k][j + delta] + eat[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][0]);
	}
	cout << ans;
	return 0;
}