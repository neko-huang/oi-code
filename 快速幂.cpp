#include <iostream>

using namespace std;
const int mod = 114514;//¸Ä

int fast_pow(int a, int n) {
	int base = a, ret = 1;
	//n >>= 1;
	while (n) {
		if (n & 1) {
			ret = ret*base;
			ret %= mod;
		}
		base = base*base;
		base %= mod;
		n >>= 1;
	}
	return ret%mod;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << int(pow(n, m));
}