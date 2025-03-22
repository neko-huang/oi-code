#include <iostream>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
struct vl {
	int a[5000], len;
	vl(int i = 0) {
		for (len=1; i;len++) {
			a[len] = i % 10; i /= 10;
		}
		len--;
	}
	int& operator[](i){
		return a[i];
	}
	void j(int i) {
		for (int o = 1; o <= i; o++) {
			a[o + 1] += a[o] / 10; a[o] %= 10;
		}
		for (; !a[len];) {
			len--; 
		}
	}
	void p() {
		for (int i = len; i>=1; i--) {
			printf("%d", a[i]);
		}
	}
};
vl operator+(vl a, vl b) {
	vl c;
	int len = max(a.len, b.len);
	for(int i=1;i<=)
}