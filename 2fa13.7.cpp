#include <iostream>
using namespace std;
int main() {
	int  ba,sum=0, cnt=1;
	int n, m;
	cin >> n>>m;
	for (; n > 0; n--) {
		cin >> ba;
		if (sum+ba <= m) {
			sum += ba;
		}
		else {
			sum = 0;
			cnt++;
			sum += ba;
		}
	}
	cout << cnt;
}