#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

	int s, a, b, x;
	cin >> s >> a >> b >> x;

	int ans = (x / (a + b)) * s * a;

	x %= (a + b);

	if (x >= a) {
		ans += a * s;
		cout << ans;
		return 0;
	}

	else {
		ans += x * s;
		cout << ans;
	}

	return 0;
}