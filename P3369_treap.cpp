#include <iostream>
using namespace std;
int read() {
	int n;
	scanf("%d", &n);
	return n;
}
int abs(int x) {
	return x > 0 ? x : -x;
}
int oil[10005];
int main() {
	int n = read();
	int maxy = -10000;
	int miny = 10000;
	for (int i = 1; i <= n; i++) {
		int nos = read();
		oil[i] = read();
		maxy = max(maxy, oil[i]);
		miny = min(miny, oil[i]);
	}
	int tmp;
	int ans = 11451419;
	for (int i = miny; i <= maxy; i++) {
		tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += abs(i - oil[j]);
		}
		ans = min(ans, tmp);
	}
	cout << ans;
}