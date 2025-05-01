#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

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

int tree[maxn][10];
bool lst[maxn];
int cnt;

bool insert(string s) {
	int rt = 0; bool ans = 0;
	for(int i = 0; i < s.length(); i++){
		if (!tree[rt][s[i]-'0']) {
			tree[rt][s[i] - '0'] = ++cnt;
		}
		rt = tree[rt][s[i] - '0'];
		if (lst[rt]) {
			ans = 1;
		}
	}
	lst[rt] = 1;
	for (int i = 0; i <= 9; i++) {
		if (tree[rt][i]) {
			return true;
		}
	}
	return ans;
}

int main() {
	int t=read();
	while (t--) {
		memset(tree, 0, sizeof(tree));
		memset(lst, 0, sizeof(lst));
		int n = read(); bool ret=0;
		string s;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			if (insert(s)) {
				ret = 1;
			}
		}
		if (ret) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}