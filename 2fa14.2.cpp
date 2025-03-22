#include <iostream>
using namespace std;
#pragma warning (disable:4996)
void in(int &a) {
	scanf("%d", &a);
}
void out(int &a) {
	printf("%d", a);
}
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}
int main() {
	int a[20005],n,m,cnt;
	in(n); in(m);
	for (int i = 1; i <= n; i++) {
		in(a[i]);
	}
	bool flag;
	for (int o = 1; o <= n; o++) {
		flag = 0;
		for (int p = 1; p <= n - o; p++) {
			if (a[p] < a[p + 1]) { swap(a[p], a[p + 1]); flag = 1; }
		}
		if (!flag) { break; }
	}
	for (cnt = 1; m > 0; cnt++) {
		m -= a[cnt];
	}
	out(--cnt);
}