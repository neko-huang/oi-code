#include <iostream>

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
int main() {
	int t=read();
	while (t--) {
		int a = read(), b = read(), n = read(), S = read();
		if (a * n < S) {
			S -= a * n;
		}
		else {
			S %= n;
		}
		if (S > b) {
			cout << "NO";
		}
		else {
			cout << "YES";
		}
		cout << '\n';
	}
	return 0;
}