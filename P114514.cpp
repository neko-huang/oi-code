#include <iostream>
using namespace std;
int main() {
	int m, n;//m<n
	cin >> m >> n;
	int i = m;
	while (i >= 1) {
		if (m % i == 0 and n % i == 0) {
			cout << i;
			return 0;
		}
		i--;
	}
}