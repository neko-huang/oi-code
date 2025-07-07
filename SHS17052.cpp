#include <iostream>
using namespace std;

const int mod = 998244353;
int pow2(int a, int x) {
	int base = a, ret = 1;
	while (x) {
		if (x & 1) {
			ret *= base;
			ret %= mod;
		}
		base *= base;
		base %= mod;
		x >>= 1;
	}
	return ret;
}
int main() {
	int n, m;
	cin >> n >> m;
	m--;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += pow(i, m);
		ans %= mod;
	}
	return 0;
}