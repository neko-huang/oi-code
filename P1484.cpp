#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const long long maxn = int(3e5 + 5);

struct node {
	long long num, v;
	bool operator <(node b) const {
		return v < b.v;
	}
};
priority_queue <node> tree;
long long v[maxn];
long long tl[maxn], tr[maxn];
bool ch[maxn];

long long read() {
	long long igt = 0, sgn = 1;
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
	long long n = read(), k = read();
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		v[i] = read();
	}
	for (long long i = 1; i <= n; i++) {
		tl[i] = i - 1;
		tr[i] = i + 1;
	}
	for (long long i = 1; i <= n; i++) {
		tree.push({ i,v[i] });
	}

	for (long long i = 1; i <= k; i++) {
		while (ch[tree.top().num]) {
			tree.pop();
		}
		node tmp = tree.top();
		tree.pop();
		if (tmp.v <= 0) {
			break;
		}
		ans += tmp.v;
		ch[tl[tmp.num]] = ch[tr[tmp.num]] = 1;
		v[tmp.num] = v[tr[tmp.num]] + v[tl[tmp.num]] - v[tmp.num];
		tree.push({ tmp.num,v[tmp.num] });
		tr[tmp.num] = tr[tr[tmp.num]];
		tl[tmp.num] = tl[tl[tmp.num]];
		tl[tr[tmp.num]] = tmp.num;
		tr[tl[tmp.num]] = tmp.num;
	}
	cout << ans;
	return 0;
}