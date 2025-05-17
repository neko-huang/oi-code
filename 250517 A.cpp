#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a < c) {
		cout << "No";
		return 0;
	}
	else if (a==c and b < d) {
		cout << "No";
		return 0;
	}
	else {
		cout << "Yes";
	}
	return 0;
}