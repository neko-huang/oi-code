#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
struct bigint {
	int a[1145], len = 1;
	void set(int p) {
		for (int i = 1; i <= 1144; i++) {
			a[i] = p;
		}
	}
	bigint(int l = 0) {
		set(0); len = 1;
		while (l) {
			a[len++] = l % 10; l /= 10;
		}
		len--;
	}
	void jinwei(int n) {
		len = n;
		for (int i = 1; i <= len; i++) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while (!a[len]) { len--; }
	}
	void print() {
		for (int i = len>1?len:1; i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
};
bigint operator+(bigint a, int b) {
	bigint c;
	for (int i = 1; i <= a.len; i++) {
		c.a[i] = a.a[i];
	}
	c.len = a.len;
	c.a[1] += b;
	c.jinwei(c.len);
	while (c.a[c.len + 1]) { c.len++; }
	return a;
}
bigint operator*(bigint a, int b) {
	bigint c;
	int len = a.len;
	for (int i = 1; i <= len; i++) {
		c.a[i] = a.a[i]*b;
	}
	c.jinwei(len+11);
	return c;
}
int main() {
	bigint fac(1);
	for (int i = 1; i <= 10; i++) {
		fac = fac * i;
	}
	fac.print();
}