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
	if()
}