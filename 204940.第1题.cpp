#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = int(4e5 + 5);

int trie[maxn][2];
int cnt = 0;
int a[maxn];
vector <int> rec[maxn];

struct node {
	int l; int r;
};
struct newnode {
	int l, r;
	int num=0;
	int cnt = 0;
};
queue <node> Q;

bool getbit(int x, int n) {
	return x & (1 << (n - 1));
}

void insert(int n,int which) {
	int now = 0;
	for (int i = 31; i >= 1; i--) {
		if (!trie[now][getbit(n, i)]) {
			trie[now][getbit(n, i)] = ++cnt;
		}
		rec[trie[now][getbit(n, i)]].push_back(which);
		now = trie[now][getbit(n, i)];
	}
	return;
}

bool cmp(newnode a, newnode b) {
	return a.l < b.l;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		insert(a[i], i);
	}

	int root = 0;
	for (int i =31; i >= 1; i--) {
		if (!trie[root][0] and !trie[root][1]) {
			break;
		}
		if (!trie[root][0]) {
			root = trie[root][1];
			for (int j = 0; j < rec[root].size(); j++) {
				Q.push({ rec[root][j],rec[root][j] });
			}
			continue;
		}
		if (!trie[root][1]) {
			root = trie[root][0];
			continue;
		}
		int tmp0 = trie[root][0];
		for (int j = 0; j < rec[tmp0].size() - 1; j++) {
			if (rec[tmp0][j]+1 != rec[tmp0][j+1]) {
				Q.push({ rec[tmp0][j], rec[tmp0][j] + 1 });
			}
		}
		if (rec[tmp0][rec[tmp0].size() - 1] < n) {
			Q.push({ rec[tmp0][rec[tmp0].size() - 1] ,rec[tmp0][rec[tmp0].size() - 1] + 1 });
		}
		tmp0 = trie[root][1];
		for (int j = 0; j < rec[tmp0].size() - 1; j++) {
			if (rec[tmp0][j] + 1 != rec[tmp0][j + 1]) {
				Q.push({ rec[tmp0][j], rec[tmp0][j] + 1 });
			}
		}
		if (rec[tmp0][rec[tmp0].size() - 1] < n) {
			Q.push({ rec[tmp0][rec[tmp0].size() - 1] ,rec[tmp0][rec[tmp0].size() - 1] + 1 });
		}
		break;
	}

	newnode maxL[4];
	maxL[1].cnt = 1;
	maxL[2].cnt = 2;
	maxL[3].cnt = 3;
	while (!Q.empty()) {
		node tmp = Q.front();
		Q.pop();
		int cac;
		if (tmp.l == tmp.r) {
			cac = a[tmp.l];
		}
		else {
			cac = a[tmp.l] ^ a[tmp.r];
		}
		if (cac >= maxL[1].num) {
			maxL[3].l = maxL[2].l;
			maxL[3].r = maxL[2].r;
			maxL[2].l = maxL[1].l;
			maxL[2].r = maxL[1].r;
			maxL[1].l = tmp.l;
			maxL[1].r = tmp.r;
			maxL[3].num = maxL[2].num; maxL[2].num = maxL[1].num; maxL[1].num = cac;
		}
	}

	sort(maxL + 1, maxL + 3, cmp);
	int ans = 0;
	if (maxL[1].r < maxL[2].l) {
		ans = max(ans, maxL[1].num + maxL[2].num);
	}
	if (maxL[2].r < maxL[3].l) {
		ans = max(ans, maxL[2].num + maxL[3].num);
	}
	if (maxL[1].r < maxL[3].l) {
		ans = max(ans, maxL[1].num + maxL[3].num);
	}
	cout << ans;
	return 0;
}