#include <iostream>
using namespace std;
bool vis[127];
int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp <= m and !vis[tmp]) {
			ans++;
			vis[tmp] = 1;
		}
		if (ans == m) {
			cout << n - i+1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}