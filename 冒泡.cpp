#include <iostream>
using namespace std;
long long a[100000] = { 0 };
int main() {
	long long n,m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int o = 2; o <= m; o++) {
			if (a[o] < a[o - 1]) {
				n = a[o];
				a[o] = a[o - 1];
				a[o - 1] = n;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << a[i]<<' ';
	}
	return 0;
}