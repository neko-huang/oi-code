#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
const int N = 5e5 + 10;
vector<int> v[N];
int fa[N];
int f[N][20], dep[N];
void dfs(int u) {
	f[u][0] = fa[u], dep[u] = dep[fa[u]] + 1;
	for (int i = 0; i < v[u].size(); i++)
		if (v[u][i] != fa[u])
			dfs(v[u][i]);
}
int lca(int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	int x = a;
	for (int i = log2(dep[a] - dep[b]); i >= 0; i--)
		if ((1 << i) <= dep[a] - dep[b])
			a = f[a][i];
	if (a == b)
		return a;
	for (int i = log2(dep[a]); i >= 0; i--)
		if (f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	return f[a][0];
}
int dist(int u, int v) {
	int ans = lca(u, v);
	ans = dep[u] - dep[ans] + dep[v] - dep[ans];
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int k;
		scanf("%d", &k);
		fa[i + 1] = k;
		v[k].push_back(i + 1);
		v[i + 1].push_back(k);
	}
	dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ans1 = (dist(a, c) + dist(b, c) - dist(a, b)) / 2;
		int ans2 = (dist(a, b) + dist(c, b) - dist(a, c)) / 2;
		int ans3 = (dist(b, a) + dist(c, a) - dist(b, c)) / 2;
		printf("%d\n", max(ans1, max(ans2, ans3)) + 1);
	}
	return 0;
}
