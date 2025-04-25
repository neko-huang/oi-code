#include <iostream>
#include <string.h>
using namespace std;
const int maxn = int(1e6 + 5);
const int maxc = 26;
int tree[maxn][maxc];
int cnt;
int sed[maxn];//ji lu zhe ge ze fu hi bu shi jie wei
void insert(string s) {
	int rt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!tree[rt][s[i] - 'a']){
			tree[rt][s[i] - 'a'] = ++cnt;
		}
		rt = tree[rt][s[i] - 'a'];
	}
	sed[rt]++;
}
int query(string s) {
	int rt = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!tree[rt][s[i] - 'a']) {
			return ans;
		}
		rt = tree[rt][s[i] - 'a'];
		ans += sed[rt];
	}
	return ans;
}
int main() {
	string tmp;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		insert(tmp);
	}
	for (int i = 1; i <= m; i++) {
		cin >> tmp;
		cout << query(tmp) << '\n';
	}
}