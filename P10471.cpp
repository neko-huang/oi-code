#include <iostream>
using namespace std;

#define int_bit 31
#define maxn int(1e5+5)
inline int get_bit(int n,int i) {
	return (n >> (i - 1)) & 1;
}

int cnt;
int tree[maxn * int_bit][2];
void insert(int n) {
	int rt = 0;
	for (int i = int_bit; i >= 0; i--) {
		if (!tree[rt][get_bit(n, i)]) {
			tree[rt][get_bit(n, i)] = ++cnt;
		}
		rt = tree[rt][get_bit(n, i)];
	}
	return ;
}
int query(int n) {
	int rt = 0, ans = 0;
	for (int i = int_bit; i >= 0; i--) {
		if (!tree[rt][!get_bit(n, i)]) {
			rt = tree[rt][get_bit(n, i)];
			ans = (ans << 1);
		}
		else {
			rt = tree[rt][!get_bit(n, i)];
			ans =(ans << 1 | 1);
		}
	}
	return ans;
}
int main() {
	int n,A;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A;
		ans = max(query(A), ans);
		insert(A);
	}
	cout << ans;
	return 0;
}