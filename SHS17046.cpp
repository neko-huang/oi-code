#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = int(1e6 + 5);
int num[maxn];
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
	int n=read();
	for (int i = 1; i <= n; i++) {
		num[i] = read();
	}
	sort(num + 1, num + 1 + n);
	for (int i = 2; i <= n; i++) {
		if (num[i] - num[i - 1] > 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}