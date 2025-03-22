#include <iostream>
using namespace std;
double fac(int n) {
	if (n == 1) { return 1; }
	return n * fac(n - 1);
}
int main() {
	double a;
	cin >> a;
	cout << fac(a);
}