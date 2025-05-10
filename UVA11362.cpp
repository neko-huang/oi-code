#include <iostream>
#include <string.h>
using namespace std;

const int maxn = int(1e4 + 5);

int tree[maxn*10][10];
bool sed[maxn*10];
int cnt;

bool insert_query(string s) {
	int rt = 0;
	bool flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!tree[rt][s[i] - '0']) {
			tree[rt][s[i] - '0'] = ++cnt;
		}
		rt = tree[rt][s[i] - '0'];
		if (sed[rt]) {
			flag = 1;
		}
	}
	sed[rt] = 1;
	for (int i = 0; i <= 9; i++) {
		if (tree[rt][s[i] - '0']) {
			flag = 1; break;
		}
	}
	return flag;
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
	int t=read();string s;
	while (t--) {
		memset(tree, 0, sizeof(tree));
		memset(sed, 0, sizeof(sed));
		cnt = 0;
		int n = read();
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			if (insert_query(s)) {
				flag = 1;
			}
		}
		if (flag) {
			printf("NO");
		}
		else {
			printf("YES");
		}
	}
	return 0;
}