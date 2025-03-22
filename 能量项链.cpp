#include<iostream>
using namespace std;
int n, a[205], dp[205][205];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int len = 2; len <= n+1; len++) {
		for (int i = 0; i+len-1 < 2*n; i++) {
			int j = i + len-1;
			for (int k = i + 1; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]+ a[i] * a[k] * a[j]) ;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i][i + n]);
	}
	cout << ans;
}