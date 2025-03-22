#include <iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) { return a; }return b;
}
struct verylong {
	int len, a[5000] = { 0 };
	verylong(int i = 0) {
		for (len = 1; i != 0; len++) {
			a[len] = i % 10; i /= 10;
		}
		len--;
	}
	int& operator[](int x) {
		return a[x];
	}
	void j(int l) {
		len = l;
		for (int i = 1; i <= len; i++) {
			a[i + 1] += a[i] / 10; a[i] %= 10;
		}
		for (; !a[len];) {
			len--;
		}
	}
	void p() {
		for (int i = max(len, 1); i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
};
verylong operator+(verylong a, verylong b) {
	verylong c;
	int len = max(a.len, b.len);
	for (int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
	}
	c.j(len + 1);
	return c;
}
verylong operator*(verylong a, int b) {
	verylong c;
	int len = a.len;
	for (int i = 1; i <= len; i++) {
		c[i] = a[i] * b;
	}
	c.j(len + 11);
	return c;
}
int main() {
	verylong temp(1), sum(0);
	int n;
	cin >> n;
	
	sum.p();
	return 0;
}