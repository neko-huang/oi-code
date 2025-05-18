#include <iostream>

using namespace std;
typedef long long ll;

void exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return;
}

ll inv(ll a, ll p) {
	ll x, y;
	exgcd(a, p, x, y);
	return x;
} 

int main() {
	int a, b;
	cin >> a >> b;
	int ans = ((inv(a, b) % b) + b) % b;
	cout << ans;
	return 0;
}