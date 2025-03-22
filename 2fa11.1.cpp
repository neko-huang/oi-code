#include <iostream>
using namespace std;
int main() {
	int b[70],len=0;
	cin >> b[0];
	for (; b[len] != 1; len++) {
		b[len + 1] = b[len]/2;
		b[len] %= 2;
	}
	for (; len >= 0; len--) {
		cout << b[len];
	}
}