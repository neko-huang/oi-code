#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n, a[120],temp,flag=0; scanf("%d", &n);
	if (n % 2 == 0) { flag = 1; }
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int l = n;
	n = (n - 1) / 2 + 1;
	for (int i = n - 1; i >= 0; i--) {
		temp = a[n - i];
		a[n - i] = a[n + i+flag];
		a[n + i+flag] = temp;
	}
	for (int i = 1; i <= l; i++) {
		printf("%d ", a[i]);
	}
}