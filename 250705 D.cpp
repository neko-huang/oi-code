#include <iostream>
#include <algorithm>
using namespace std;

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

long long bl[int(2e5 + 5)];
int main() {
	int t = read();
	while (t--) {
		bool flag = 0;
		int n = read();
		if (n == 2) {
			cout << "Yes\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			bl[i] = read();
		}
		sort(bl + 1, bl + n + 1);
		for (int i = 2; i < n; i++) {
			if (bl[i - 1] * bl[i + 1] != bl[i] * bl[i]) {
				cout << "No\n"; flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		cout << "Yes\n";
	}
}