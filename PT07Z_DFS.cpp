#include <iostream>
#include <vector>

using namespace std;
const int maxn = int(1e4 + 5);

int d[maxn];
int node=0;
vector <int> G[maxn];

void dfs(int x, int fa) {
	for (int i = 0; i < G[x].size(); i++) {
		if (G[x][i] == fa) {
			continue;
		}
		d[G[x][i]] = d[x] + 1;
		if (d[node] < d[G[x][i]]) {
			node = G[x][i];
		}
		dfs(G[x][i], x);
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
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt* sgn;
}
int main() {
	int n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	d[node] = 0;
	dfs(node, 0);
	cout << d[node];
	return 0;
}