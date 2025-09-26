#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
const int maxn = int(1e5 + 5);


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


struct pos {
	int x, y;
};

struct node {
	int l, r;
	int sum;
	int lzt;
};

vector <pos> toaxis;
node tree[maxn << 2];

void upd(int x) {
	tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
	return;
}

void pushdown(int x) {
	if (!tree[x].lzt) { return; }
	tree[x * 2].lzt += tree[x].lzt;
	tree[x * 2 + 1].lzt += tree[x].lzt;
	tree[x * 2].sum += (tree[x].r - tree[x].l + 1) * tree[x].lzt;
	tree[x * 2 + 1].sum += (tree[x].r - tree[x].l + 1) * tree[x].lzt;
	tree[x].lzt = 0;
	return;
}

void build(int x, int bl, int br) {
	tree[x].l = bl;
	tree[x].r = br;
	tree[x].lzt = 0;
	if (bl == br) {
		tree[x].sum = 0;
		return;
	}
	int mid = (bl + br) >> 1;
	build(x * 2, bl, mid);
	build(x * 2 + 1, mid + 1, br);
	upd(x);
	return;
}

void add(int x, int al, int ar, int n) {
	if (al <= tree[x].l and tree[x].r <= ar) {
		tree[x].sum += (tree[x].r - tree[x].l + 1) * n;
		tree[x].lzt += n;
		return;
	}
	pushdown(x);
	int mid = (tree[x].l + tree[x].r) >> 1;
	if (al <= mid) {
		add(x * 2, al, ar, n);
	}
	if (ar >= mid + 1) {
		add(x * 2 + 1, al, ar, n);
	}
	upd(x);
	return;
}

void query(int x, int ql, int qr) {

}
int main() {

}