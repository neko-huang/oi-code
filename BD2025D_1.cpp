#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n % 2) {
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
		}
		return 0;
	}
	else {
		for (int i = 1; i <= n; i += 2) {
			cout << i + 1 << ' ' << i << ' ';
		}
		return 0;
	}
}