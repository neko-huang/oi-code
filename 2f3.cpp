#include <iostream>
using namespace std;
short a[1145];
void swap(short &a, short &b) {
	short tmp = a; a = b; b = tmp;
}
void back(bool &a) {
	a = !a;
}
void qsort(int h, int t) {
	int middle = a[(h + t) / 2],i=h,j=t;
	while (i <= j) {
		while (a[i] < middle) { i++; }
		while (a[j] > middle) { j--; }
		if (i <= j) { swap(a[i], a[j]); i++; j--; }
	}
	if (i < t)qsort(i, t);
	if (h < j)qsort(h, j);
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	qsort(1, n);
	bool flag=0;
	int h = 1, t = n;
	while (h <= t) {
		if (flag) {
			back(flag); cout << a[h++]<<endl;
		}
		else {
			back(flag); cout << a[t--]<<endl;
		}
	}
}