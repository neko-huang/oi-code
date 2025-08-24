#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = int(5e4 + 5);

struct node {
	int l, r;
	int sum,lzt;
};

node tree[maxn << 3];

void upd(int x) {
	tree[x].sum = max(tree[x * 2].sum , tree[x * 2 + 1].sum);
}

void pushdown(int x) {
	if (tree[x].lzt) {
		int lson = x * 2, rson = x * 2 + 1;
		tree[lson].sum += tree[x].lzt;
		tree[rson].sum += tree[x].lzt;
		tree[lson].lzt += tree[x].lzt;
		tree[rson].lzt += tree[x].lzt;
		tree[x].lzt = 0;
	}
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

void insert(int x,int al,int ar) {
	if (al <= tree[x].l and tree[x].r <= ar) {
		tree[x].sum += 1;
		tree[x].lzt++;
		return;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	pushdown(x);
	if (al <= mid) {
		insert(x * 2, al, ar);
	}
	if (mid < ar) {
		insert(x * 2 + 1, al, ar);
	}
	upd(x);
	return;
}

int query(int x, int ql, int qr) {
	if (ql <= tree[x].l and tree[x].r <= qr) {
		return tree[x].sum;
	}
	int mid = (tree[x].l + tree[x].r) >> 1;
	pushdown(x);
	int ret = 0;
	if (ql <= mid) {
		ret = max(ret, query(x * 2, ql, qr));
	}
	if (mid < qr) {
		ret = max(ret, query(x * 2 + 1, ql, qr));
	}
	return ret;
}

vector <int> place[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	int n; cin >> n;build(1, 1, 2*n);
	for (int i = 1; i <= 2*n; i++) {
		int tmp;
		cin >> tmp;
		place[tmp].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		insert(1, place[i][0], place[i][1]);
	}
	cout << query(1, 1, n);
	return 0;
}