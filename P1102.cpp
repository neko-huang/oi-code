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
const int maxn = int(2e5 + 5);
int a[maxn];
int main() {
	int n = read();
	int c = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int l = 1, r = 1;long long ans = 0;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		while (a[l] < a[i] - c and l <= n) {
			l++;
		}
		while (a[r] <= a[i] - c and r <= n) {
			r++;
		}
		if(a[i]-a[l]==c)ans += (r - l);
	}
	cout << ans;
	return 0;
}