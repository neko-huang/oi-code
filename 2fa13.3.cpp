#include <iostream>
using namespace std;
int a[10086];
void swap_i(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int n,cnt=0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	bool f = 0;
	for (int i = 1; i < n; i ++ ) {
		f = 0;
		for (int o = 1; o <= n - i; o++) {
			if (a[o] > a[o + 1]) {
				swap_i(a[o], a[o + 1]); f = 1; cnt++;
			}
		}
		if (f==0) {
			break;
		}
	}
	cout << cnt;
}