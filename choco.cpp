#include <iostream>
using namespace std;
const int maxn = int(1e5 + 5);
int a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("choco.cpp", "r", stdin);
	freopen("choco.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0, len = 0;
	int sum = 0;
	int mas = 0;
	for (int i = 1; i <= n; i++) {
		mas = max(mas, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			ans = max(ans, len);
			len = 1;
		}
		else {
			len++;
		}
	}
	cout << ans;
	return 0;
}