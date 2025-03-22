#include <iostream>
using namespace std;
int main() {
	int a;unsigned long long sum = 1; cin >> a;
	while (a > 1) {
		sum *=2;
		a--;
	}
	cout << sum;
	return 0;
}