#include <iostream>

using namespace std;
typedef long long ll;
const ll maxn = int(3e6 + 5);

ll inv[maxn];

int main() {

	ll n, p;
	cin >> n >> p;

	inv[1] = 1;
	printf("1\n");
	for (ll i = 2; i <= n; i++) {
		inv[i] = (p - p / i) * inv[p % i];
		inv[i] %= p;
		printf("%lld\n", inv[i]);
	}
	return 0;
}