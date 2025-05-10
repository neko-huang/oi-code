#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	if (m == 1 and n >= 1600 and n <= 2999) {
		cout << "Yes";
		return 0;
	}
	if (m == 2 and n >= 1200 and n <= 2399) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}