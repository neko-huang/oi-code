#include <iostream>
#include <vector>
#include <vector>

#define ls son[0]
#define rs son[1]

using namespace std;
const int maxn = int(1e5 + 5);


int n;
int tot;
int rt;

struct node {
	int son[2];
	int siz, cnt;
	int fa;
};

node tree[maxn];

void init() {
	for (int i = 1; i <= n; i++) {
		tree[i].son[0] = tree[i].son[1] = tree[i].siz = tree[i].cnt = tree[i].fa = 0;
	}
}

bool get(int x) {
	return tree[tree[x].fa].son[1]==x;
}

void upd(int x) {
	tree[x].siz = tree[tree[x].ls].siz + tree[tree[x].rs].siz + 1;
	return;
}

int newnode(int x) {
	tree[++tot].cnt = x;
	tree[tot].siz = 1;
	return tot;
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

void insert(int n) {
	int now = rt, f = 0;
	if (now) {
		f = now;
		now = tree[now].son[n >= tree[now].cnt];
	}
	now = newnode(n);
	tree[now].fa = f;
	tree[f].son[n >= tree[now].cnt]=now;
	return;
}

void delnode(int n) {
	int now = rt, f = 0;
	if (now and tree[now].cnt!=n) {
		f = now;
		now = tree[now].son[n >= tree[now].cnt];
	}
}