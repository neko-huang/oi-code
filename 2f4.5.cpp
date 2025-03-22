#include <iostream>
using namespace std;
int main() {
	int m, n,sum=0;
	cin >> m >> n;
	while (m <= n) {
		if (m % 3 == 0 or m % 5 == 0) { sum += m;}
		m++;
	}
	cout << sum;
	return 0;//ASCII
}