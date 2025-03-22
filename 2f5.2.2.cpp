#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n, temp=0; cin >> n;
	for (ll i = 1; i <= n; i++) {
		temp = 0;
		for (ll o = 1; o < i; o++) {
			if (i % o == 0) {temp += o;}
		}
		if (temp == i) { printf("%lld\n", temp); }
	}
	return 0;
}