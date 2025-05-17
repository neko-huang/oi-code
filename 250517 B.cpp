#include <iostream>
#include <climits>

using namespace std;
typedef unsigned long long ll;

ll num;
ll tpow[20];
int main() {
	int n, k;
	cin >> n >> k;
	tpow[0] = 1;
	tpow[1] = 10;
	for (int i = 2; i <= k; i++) {
		tpow[i] = tpow[i - 1] * 10;
	}
	ll tmp = 1;ll at;
	for (int i = 1; i <= n; i++) {
		cin >> at;
		if (LLONG_MAX / tmp <= at) {
			tmp = 1;
			continue;
		}
		tmp *= at;
		if (tmp  >= tpow[k]) {
			tmp = 1;
		}
	}
	cout << tmp;
}