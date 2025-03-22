#include <iostream>
using namespace std;
int main() {
	long long a, sum=0;
	cin >> a;
	while (a > 0) {
		sum += a;
		a--;
	}
	cout << sum;
	return 0;
}