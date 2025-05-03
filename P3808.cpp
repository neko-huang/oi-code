#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int maxs = int(1e6 + 5);

queue <int> bfs;
char tree[maxs][26];
int fail[maxs];
int lst[maxs];
int cnt;

void insert(string s) {
	int rt = 0;
	for (int i = 0; i < s.length();i++) {
		if (!tree[rt][s[i] - 'a']) {
			tree[rt][s[i] - 'a'] = ++cnt;
		}
		rt=tree[rt][s[i] - 'a'];
	}
	lst[cnt]++;
	return;
}

void build() {
	for (int i = 0; i < 26; i++) {
		if (tree[0][i]) {
			bfs.push(tree[0][i]);
		}
	}
	while (!bfs.empty()) {
		int tmp = bfs.front(); bfs.pop();
		for (int i = 0; i < 26; i++) {
			if (tree[tmp][i]) {
				fail[tree[tmp][i]] = tree[fail[tmp]][i];
				bfs.push(tree[tmp][i]);
			}
			else {
				tree[tmp][i] = tree[fail[tmp]][i];
			}
		}
	}
	return ;
}

int query(string s) {
	int rt = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		rt = tree[rt][s[i] - 'a'];
		for (int j = rt; lst[j] != -1 and rt; j = fail[j]) {
	  		ans += lst[j];
			lst[j] = -1;
		}
	}
	return ans;
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
	string mode,text;
	int n = read();
	for (int i = 1; i <= n; i++) {
		cin >> mode;
		insert(mode);
	}
	build();
	cin >> text;
	cout << query(text);
	return 0;
}