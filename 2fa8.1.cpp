#include <iostream>
using namespace std;
int main() {
#pragma warning (disable:4996)
	double a[10], b[10]; int small=1;
	for (int i = 1; i <= 4; i++) {
		scanf("%lf", & a[i]);
	}
	for (int i = 1; i <= 4; i++) {
		for (int o = 1; o <= 4; o++) {
			if (a[small] > a[o]) {
				small = o;
			}
		}
		b[i] = a[small];
		a[small] = 9e99;
		small = 1;
	}
	for (int i = 1; i <= 4; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}