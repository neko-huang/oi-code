#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main(){
	double a[5], temp;
	for (int i = 1; i <= 4; i++) {
		scanf("%lf", &a[i]);
	}
	for (int i = 2; i <= 4; i++) {
		temp = a[i];
		for (int o = i-1; o >= 1; o--) {
			if (a[o] > temp) {
				a[o + 1] = a[o];
				a[o] = temp;
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		cout<<a[i];
	}
}