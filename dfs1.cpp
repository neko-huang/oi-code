#include <iostream>
#include <vector>

using namespace std;
const int maxn = int(1e6 + 5);

struct node {
	int l, r;
	int sum;
};

node segtree[maxn << 2];

void upd(int x) {
	segtree[x].sum = segtree[x * 2].sum + segtree[x * 2 + 1].sum;
	return;
}

void build(int x,int bl, int br) {
	segtree[x].l = bl;
	segtree[x].r = br;
	if (bl == br) {
		segtree[x].sum = 0;
		return;
	}
	int mid = (bl + br) >> 1;
	build(x * 2, bl, mid);
	build(x * 2 + 1, mid + 1, br);
	upd(x);
	return;
}

void insert(int x, int n, int ch) {
	if (segtree[x].l == n and segtree[x].r == n) {
		segtree[x].sum += ch;
		return;
	}
	if (n >= segtree[x].l) {
		insert(x * 2, n, ch);
	}
	if (n <= segtree[x].r) {
		insert(x * 2 + 1, n, ch);
	}
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

int v[maxn];
vector <int> tree[maxn];
int dfn[maxn];
int intime[maxn], outtime[maxn];
int cnt; int timecnt;

void dfs(int u, int fa) {
	for (int i = 0; i <= tree[u].size(); i++) {
		intime[tree[u][i]] = ++timecnt;                                                                                                                ] = tree[u][i];
		dfs(i, u);
		outtime[tree[u][i]] = timecnt;
	} 
}

int main() {
	int n = read(), m = read(), r = read();
	for (int i = 1; i <= n; i++) {
		v[i] = read();
	}
	int u, v;
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		tree[u].push_back(v);
	}
	
}