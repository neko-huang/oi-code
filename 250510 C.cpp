#include <iostream>

using namespace std;
typedef unsigned long long ll;

int main() {
	ll n;
	cin >> n;

	ll sum1 = 0,sum2=0;
	for (int i = 1; i <= n; i++) {
		ll tmp;
		cin >> tmp;
		sum1 += tmp;
		sum2 += tmp * tmp;
	}
	sum1 *= sum1;
	sum1 -= sum2;
	sum1 /= 2;
	cout << sum1;
	return 0;
}