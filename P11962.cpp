#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = int(2e5 + 5);

vector <int> tree[maxn];
bool vis[maxn];

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c < '0' or c>'9') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int ura[maxn << 1]; int cnt;
void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < tree[x].size(); i++) {
		if(!vis[tree[x][i]])
		{
			ura[cnt++] = tree[x][i];
			dfs(tree[x][i]);
			ura[cnt++] = tree[x][i];
		}
	}
	vis[x] = 0;
}
int main() {
	int n=read();
	int u, v;
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < cnt; i++) {
		int ans1 = 0, ans2 = 0;
		if (!vis[ura[i]]) {
			for (int j = i; j < cnt; j += 2) {
				if (ura[j] != ura[i]) {
					ans1++;
				}
			}
			for (int j = i; j >= 0; j -= 2) {
				if (ura[j] != ura[i]) {
					ans2++;
				}
			}
			vis[ura[i]] = 1;
			cout << max(ans1, ans2) << '\n';
		}
	}
}