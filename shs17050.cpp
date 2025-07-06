#include <iostream>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = int(3e6 + 5);

struct node {
	int l, r;
	int min;
	int lzt;
};

node tree[maxn << 2];
int a[maxn];

void upd(int x) {
	tree[x].min = min(tree[x * 2].min, tree[x * 2 + 1].min);
	return ;
}

void pushdown(int x) {
	if (tree[x].lzt) {
		tree[x * 2].lzt += tree[x].lzt;
		tree[x * 2 + 1].lzt += tree[x].lzt;
		tree[x * 2].min += tree[x].lzt;
		tree[x * 2 + 1].min += tree[x].lzt;
		tree[x].lzt = 0;
	}
	return;
}

void build(int x, int bl, int br) {
	tree[x].l = bl;
	tree[x].r = br;
	tree[x].lzt = 0;
	if (bl == br) {	
		tree[x].min = a[bl];
		return;
	}
	int mid = (bl + br) >> 1;
	build(x * 2, bl, mid);
	build(x * 2 + 1, mid + 1, br);
	upd(x);
	return;
}

void change(int x, int cl, int cr, int z) {
	if (cl <= tree[x].l and tree[x].r <= cr) {
		tree[x].min += z;
		tree[x].lzt += z;
		return ;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	pushdown(x);
	if (cl <= mid) {
		change(x * 2, cl, cr, z);
	}
	if (mid < cr) {
		change(x * 2 + 1, cl, cr, z);
	}
	upd(x);
	return ;
}

int query(int x, int ql, int qr) {
	if (ql <= tree[x].l and tree[x].r <= qr) {
		return tree[x].min;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	pushdown(x);
	int ret = inf;
	if (ql <= mid) {
		ret = min(ret, query(x * 2, ql, qr));
	}
	if (mid < qr) {
		ret = min(ret, query(x * 2 + 1, ql, qr));
	}
	
	return ret;
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
	int n = read(), p = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}

	build(1, 1, n);
	while (p--) {
		int x = read(), y = read(), z = read();
		if (x > y) {
			swap(x, y);
		}
		change(1, x, y, z);
	}
	printf("%d", query(1, 1, n));
	return 0;
}