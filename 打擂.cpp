#include <iostream>
using namespace std;
long long a[100000] = { 0 };
int main() {
	long long n, m=-9223372036854775807;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			m = a[i];
		}
	}
	cout << m;
	return 0;
}
