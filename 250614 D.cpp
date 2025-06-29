#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = int(1e3 + 5);
const int maxw = int(1 << 10) + 5;
const int inf = 2147483647;

struct node {
	int v, w;
};

vector <node> G[maxn];
bool vis[maxn];
queue <node> bfs;
int ans[maxn][maxw];

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
	int n = read(), m = read();
	int ret = 0x3f3f3f3f;
	for (int i = 1; i <= m; i++) {
		int a = read(), b = read(), w = read();
		G[a].push_back({ b,w });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < maxw; j++) {
			ans[i][j] = inf;
		}
	}

	bfs.push({ 1,0 });
	ans[1][0] = 0;

	while (!bfs.empty()) {
		node tmp = bfs.front();
		bfs.pop();
		for (int i = 0; i < G[tmp.v].size(); i++) {
			int tmpw = G[tmp.v][i].w;
			int tmpv = G[tmp.v][i].v;
			int now = tmp.w ^ tmpw;

			if (tmpv == n) {
				ret = min(ret, now);
			}
			if (ans[tmpv][now] > ans[tmp.v][now] + 1) {
				ans[tmpv][now] = ans[tmp.v][now] + 1;
				bfs.push({ tmpv,now });
			}
		}
	}
	if (ret == 0x3f3f3f3f) {
		cout << "-1";
		return 0;
	}
	cout << ret;
	return 0;
}