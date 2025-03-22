#include <iostream>
using namespace std;
#pragma warning (disable:4996)
void swap(double &a,double &b) {
	double temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	double a[15] = { 0 };
	for (int i = 1; i <= 10; i++) {
		scanf("%llf", &a[i]);
	}
	for (int i = 1; i <= 10; i++) {
		for(int o=1;o<=10-i;o++){
			if (a[o] > a[o + 1]) {
				swap(a[o], a[o + 1]);
			}
		}
	}
	for (int i = 1; i <= 10; i++) {
		printf("%llf", a[i]);
	}
}