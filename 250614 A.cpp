#include <iostream>
using namespace std;
const int maxn = int(1e2 + 5);
int a[maxn];
int main() {
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= k) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}