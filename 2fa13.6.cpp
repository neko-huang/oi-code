#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int a[1005];short b[1005],a1[1005];
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}
int main() {
	int n;double sum = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= n - i; p++) {
			if (a[p] > a[p + 1]) {
				swap(b[p], b[p + 1]);
				swap(a[p], a[p + 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		sum += a[i] * (n - i);
		printf("%d ", b[i]);
	}
	printf("\n%.2lf", sum / n);
}