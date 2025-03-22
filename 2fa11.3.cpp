#include <iostream>
using namespace std;
int main() {
	int n,cnt=0;
	cin >> n;
	for (int q = 1; q <= n / 5; q++) {
		for (int w = 1; w <= n / 2 ; w++) {
			for (int e = 1; e <= n ; e++) {
				if (q * 5 + w * 2 + e==n) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return  0;
}