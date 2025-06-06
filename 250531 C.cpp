#include <iostream>

using namespace std;
const int maxn = int(1e6 + 5);

struct node {
	int l, r;
	int min;
	int lzt;
};

node tree[maxn << 2];

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

void upd(int x) {
	tree[x].min = min(tree[x * 2].min, tree[x * 2 + 1].min);
}

void build(int x, int bl, int br) {
	tree[x].l = bl;
	tree[x].r = br;
	tree[x].lzt = 0;
	if (bl == br) {
		tree[x].min = 0;
		return;
	}
	int mid = (bl + br) / 2;
	build(x * 2, bl, mid);
	build(x * 2 + 1, mid + 1, br);
	upd(x);
	return;
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

void insert(int x, int il, int ir) {
	if (il <= tree[x].l and tree[x].r <= ir) {
		tree[x].min++;
		tree[x].lzt++;
		return;
	}
	pushdown(x);
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (mid >= il) {
		insert(x * 2, il, ir);
	}
	if (mid < ir) {
		insert(x * 2 + 1, il, ir);
	}
	upd(x);
	return;
}

int query(int x, int ql, int qr) {
	if (ql <= tree[x].l and tree[x].r <= qr) {
		return tree[x].min;
	}
	pushdown(x);
	int mid = (tree[x].l + tree[x].r) >> 1;
	int ret = 0x3f3f3f3f;
	if (mid >= ql) {
		ret = min(ret, query(x * 2, ql, qr));
	}
	if (mid < qr) {
		ret = min(ret, query(x * 2 + 1, ql, qr));
	}
	return ret;
}

int main() {
	int n = read(), m = read();
	int l, r;
	build(1, 1, n);
	while (m--) {
		l = read(), r = read();
		insert(1, l, r);
	}
	cout << query(1, 1, n);
	return 0;
}