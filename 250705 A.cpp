#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	while (n--) {
		int tmp;
		cin >> tmp;
		sum += tmp;
	}
	if (sum > m) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}