#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 400 / n;
	if (ans * n != 400) {
		cout << "-1";
		return 0;
	}
	else {
		cout << ans;
	}
	return 0;
}