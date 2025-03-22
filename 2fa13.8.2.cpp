#include <iostream>
using namespace std;
typedef unsigned long long ll;
#pragma warning (disable:4996)
struct verylong {
	int len, a[11451] = {0};
	void set(int L,int n) {
		for (int i = 1; i <= L; i++) {
			a[i] = n;
		}
	}
	verylong(ll n = 0) {
		for (len = 1; n; len++) {
			a[len] = n % 10; n /= 10;
		}
		len--;
	}
	int& operator[](int i) {
		return a[i];
	}
	void jinwei(int LEN) {
		len = LEN;
		for (int i = 1; i <= len; i++) {
			a[i + 1] += a[i] / 10; a[i] %= 10;
		}
		while (!a[len]) {
			len--;
		}
	}
	void print() {
		for (int i = len > 1 ? len : 1; i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
	int check(int m) {
		int cnt=0;
		for (int i = 1; i <= len; i++) {
			if (a[i] == m) {
				cnt++;
			}
		}
		return cnt;
	}
};
verylong operator*(verylong a, int b) {
	int len = a.len;
	for (int i = 1; i <= len; i++) {
		a[i] *= b;
	}
	a.jinwei(len + 11);
	return a;
}
int main() {
	verylong fac(1);
	int a, n, m;
	scanf("%d", &a);
	for (; a > 0; a--) {
		scanf("%d%d", &n, &m);
		for (; n >= 2; n--) {
			fac = fac * n;
		}
		cout << fac.check(m)<<'\n';
		fac.set(fac.len, 0);
		fac = verylong(1);
	}
}