#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = int(1e3 + 5);

struct node {
	int u, v, w;
};

vector <node> side;

int fa[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}

bool cmp(node a, node b) {
	return a.w < b.w;
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
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	while (m--) {
		int u = read(), v = read(), w = read();
		side.push_back({ u,v,w });
	}
	sort(side.begin(), side.end(), cmp);
	int cnt = 0, ans = 0;
	for (int i = 0; i < side.size(); i++) {
		int fu = find(side[i].u), fv = find(side[i].v);
		if (fu == fv) {
			continue;
		}
		merge(fu, fv);
		cnt++;
		ans += side[i].w;
		if (cnt >= (n - k)) {
			cout << ans << '\n';
			return 0;
		}

	}cout << "No Answer";
	return 0;
}