#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long ans = 0;
	int a, b;
	for (int i = 1; i <= n/2; i++) {
		cin >> a >> b;
		ans += a;
	}
	if (n % 2) {
		cin >> a;
		ans += a;
	}
	cout << ans;
	return 0;
}