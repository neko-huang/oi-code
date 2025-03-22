#include <iostream>
using namespace std;
int age(int n) {
	if (n == 1) { return 10; }
	return age(n - 1) + 2;
}
int main() {
	int n;
	cin >> n;
	cout << age(n);
}