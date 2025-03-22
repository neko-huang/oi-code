#include <iostream>
using namespace std;
#pragma warning (disable:4996)
double a[15];
int main() {
	double temp;int small;
	for (int i = 1; i <= 10; i++) {
		scanf("%lf", &a[i]);
	}
	for (int p = 1; p <= 10; p++) {
		small = p;
		for (int i = p; i <= 10 ; i++) {
			if (a[small] > a[i]) {
				small = i;
			}
		}
		if (small != p) {
			temp = a[p];
			a[p] = a[small];
			a[small] = temp;
		}
	}
	for (int i = 1; i <= 10; i++) {
		cout << a[i];
	}
}