#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1505;
vector <int> edge[maxn];
int dp[maxn][2];
int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while(c>'9' or c<'0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int main() {
	int n = read();
	int rt, k, tmp;
	for (int i = 1;i <= n;i++) {
		rt = read();k = read();
		for (int j = 1;j <= k;j++) {
			edge[rt].push_back(read());
		}
	}
	for (int i = 1;i <= n;i++) {
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	for (int i = 1;i <= n;i++) {
		int sum1 = 0, sum2 = 0;
		for (int j = 0;j < edge[i].size();j++) {
			sum1 += dp[edge[i][j]][1];
			sum2 += min(dp[edge[i][j]][0], dp[edge[i][j]][1]);
		}
		dp[i][0] += sum1;
		dp[i][1] += sum2;
	}
	int ans = 0x3f3f3f3f;
	for (int i = 1;i <= n;i++) {
		ans = min(ans, min(dp[i][0],dp[i][1]));
	}
	printf("%d", ans);
	return 0;
}