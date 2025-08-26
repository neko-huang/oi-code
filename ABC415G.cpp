//abc415G
/*

 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 90000;
int n, dp[N + 5], ans;
int m, c[305]; // i 个瓶子最多能换多少可乐
void solve() {
	cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		c[x] = max(c[x], y);
	}
	for (int i = 1; i <= N; i++) dp[i] = i;
	for (int i = 1; i <= 300; i++)
		for (int j = i; j <= N; j++) // 完全背包
			dp[j] = max(dp[j], dp[j - i + c[i]] + i);
	if (n <= N) ans = dp[n];
	else
		for (int i = 2; i <= 300; i++) {
			int t = (n - N + i - c[i] - 1) / (i - c[i]);
			ans = max(ans, t * i + dp[n - t * (i - c[i])]);
		}
	cout << ans;
}

signed main() {
	solve();
	return 0;
}
