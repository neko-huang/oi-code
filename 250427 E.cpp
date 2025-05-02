#include <iostream>

using namespace std;
const int maxn=int(5e5 + 5);
const int maxc = 26;

int tree[maxn][26];
int father[maxn*26];
int cnt;
int num[maxn];
bool delx[maxn];

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

int insert(int rt,string s,int x) {
	if (x + 1 == s.length()) {
		num[rt]++;
		return 1;
	}
	if (!tree[rt][s[x] - 'a']) {
		tree[rt][s[x] - 'a'] = ++cnt;
	}
	if (delx[tree[rt][s[x] - 'a']]) {
		return 0;
	}
	father[tree[rt][s[x] - 'a']] = rt;
	int ans=insert(tree[rt][s[x] - 'a'], s, x + 1);
	num[rt] += ans;
	return ans;
}

int del(int rt, string s, int x) {
	if (x + 1 == s.length()) {
		delx[rt] = 1;
		return num[rt];
	}
	if (!tree[rt][s[x] - 'a']) {
		tree[rt][s[x] - 'a'] = ++cnt;
	}
	if (delx[tree[rt][s[x] - 'a']]) {
		return 0;
	}
	int ans=del(tree[rt][s[x] - 'a'], s, x + 1);
	num[rt] -= ans;
	return ans;
}

int main() {
	int q=read();
	for (int i = 1; i <= q; i++) {
		int opt = read(); string s;
		cin >> s;
		if (opt == 1) {
			del(0, s, 0);
			printf("%d\n", num[0]);
		}
		else {
			insert(0, s, 0);
			printf("%d\n", num[0]);
		}
	}
	return 0;
}