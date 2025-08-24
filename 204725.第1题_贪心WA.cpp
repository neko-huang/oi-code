#include <iostream>
#include <cstring>

using namespace std;

long long sq10[20];
bool buc[10];

void init() {
	sq10[0] = 1;
	for (long long i = 1; i <= 19; i++) {
		sq10[i] = sq10[i - 1] * 10;
	}
}

void dis(long long x) {
	memset(buc, 0, sizeof(buc));
	while (x) {
		buc[x % 10] = 1;
		x /= 10;
	}
	return;
}

long long len1(long long x) {
	for (long long i = 0; i < 19; i++) {
		if (x >= sq10[i] and x < sq10[i + 1]) {
			return i + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init();
	/*cout << len1(114514) << '\n';
	dis(114514);
	for (int i = 0; i <= 9; i++) {
		cout << buc[i];
	}
	*/
	long long n, x;
	cin >> n >> x;
	if (x == 1 and n != 1) {
		cout << "-1";
		return 0;
	}
	long long cnt = 0;
	for (long long i = x; len1(i) <= n;) {
		dis(i);
		long long tmp = 0;
		for (long long i = 9; i >= 0; i--) {
			if (buc[i]) {
				tmp = i;
				break;
			}
		}
		if (tmp == 0) {
			cout << "-1";
			return 0;
		}
		i *= tmp;
		if (len1(i)<=n) {
			cnt++;
		}
	}
	cout << cnt;
}