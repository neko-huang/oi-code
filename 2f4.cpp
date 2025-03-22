#include <iostream>
using namespace std;
short a[11];
void swap(short& a, short& b) {
	short tmp = a; a = b; b = tmp;
}

void qsort(int h, int t) {
	int middle = a[(h + t) / 2], i = h, j = t;
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
		cin >> a[1] >> a[2] >> a[3];
		if (a[1] == a[2] and a[2] == a[3]) {
			cout << "db\n"; continue;
		}
		qsort(1, 3);
		if (!(a[3] - a[1]<a[2] and a[3] + a[1]>a[2])) {
			cout << "bssjx\n"; continue;
		}
		if (a[1] * a[1] + a[2] * a[2] == a[3] * a[3]) {
			if (a[1] == a[2]) {
				cout << "dyzj\n"; continue;
			}
			else {
				cout << "ptzj\n"; continue;
			}
		}
		if (a[1] * a[1] + a[2] * a[2] > a[3] * a[3]) {
			if (a[1] == a[2]) {
				cout << "dyrj\n"; continue;
			}
			else {
				cout << "ptrj\n"; continue;
			}
		}
		if (a[1] * a[1] + a[2] * a[2] < a[3] * a[3]) {
			if (a[1] == a[2]) {
				cout << "dydj\n"; continue;
			}
			else {
				cout << "ptdj\n"; continue;
			}
		}
	}
}