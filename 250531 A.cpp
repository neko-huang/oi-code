#include <iostream>
using namespace std;
const int maxn = int(1e2 + 5);
int a[maxn];
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - 1] > s) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}