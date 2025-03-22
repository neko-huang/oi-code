#include <iostream>
using namespace std;
long long max(long long a, long long b) {
	if (a > b) {
		return a;
	}
	return b;
}
int f3_3_1_1() {
	int a,b,c,d,e,f;
	cin >> a;
	int m = a;
	int i = 0;
	while (i < 5) {
		if (i==1) {
			m = max(m, b);
		}
		if (i == 2) {
			m = max(m, c);
		}
		if (i == 3) {
			m = max(m, d);
		}
		if (i == 4) {
			m = max(m, e);
		}
		if (i == 5) {
			m = max(m, f);
		}
	}
	cout << m;
	return 0;
}
int f3_3_1_2() {
	int i = 0,m=0,a;
	while (i < 5) {
		cin >> a;
		if (a > m) {
			m = a;
		}
		i++;
	}
	cout << m;
	return 0;
}
int f3_3_2_2() {
	int i = 0, a; long long m = 0;
	while (i < 3) {
		cin >> a;
		m += a;
		i++;
	}
	cout << m;
	return 0;
}
int main() {
	f3_3_1_2();
}