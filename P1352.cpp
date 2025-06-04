#include <iostream>
#include <vector>

using namespace std;
const int maxn = int(6e3 + 5);

int r[maxn];
vector <int> tree[maxn];
int dp[maxn][2];
bool vis[maxn];

void f(int x) {
	dp[x][1] = r[x];
	for (int i = 0; i < tree[x].size(); i++) {
		f(tree[x][i]);
		dp[x][1] += dp[tree[x][i]][0];
		dp[x][0] += max(dp[tree[x][i]][1], dp[tree[x][i]][0]);
	}
	return;
}

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
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
	int n=read();
	for (int i = 1; i <= n; i++) {
		r[i] = read();
	}
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		tree[v].push_back(u);
		vis[u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			f(i);
			cout << max(dp[i][0], dp[i][1]);
			return 0;
		}
	}
	return 0;
}