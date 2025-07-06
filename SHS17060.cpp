#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	int t = 2;
	while (t--) {
		cout << 5;
		for (int i = 1; i < n; i++) {
			cout << 0;
		}
	}
	return 0;
}