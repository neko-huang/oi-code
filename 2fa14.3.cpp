#include <iostream>
using namespace std;
int a[100], b[100],s1[100],s2[100]; char tmp;
#pragma warning (disable:4996)
void prime(int a[], int b) {
	a[1] = 2;
	int cnt = 1; bool flag;
	for (int i = 3; i <= b; i++) {
		flag = 0;
		for (int p = 1; p <= cnt;p++) {
			if (i % a[p] == 0) {
				flag = 1; break;
			}
		}
		if (!flag) { a[++cnt] = i; }
	}
}
int main() {
	prime(a, 100); int len1=0, len2=0;
	for (len1 = 1; 1;) {
		scanf("%c", &tmp);
		if (tmp=='+') {
			break;
		}
		if (tmp == ',') { len1++; continue; }
		s1[len1] *= 10;
		s1[len1] += tmp - '0';
	}
	for (len2 = 1; 1;) {
		scanf("%c", &tmp);
		if (tmp == '\n') {
			break;
		}
		if (tmp == ',') { len2++; continue; }
		s2[len2] *= 10;
		s2[len2] += tmp - '0';
	}
	int len = len1 > len2 ? len1 : len2;
	for (int i = 1; i <= len; i++) {
		b[i] += s1[len1 - i + 1] + s2[len2 - i + 1];
	}
	for (int i = 1; i <= len + 1; i++) {
		/*for (int i = len + 1; i >= 2; i--) {
			printf("%d,", b[i]);
		}
		printf("%d\n", b[1]);*/
		b[i + 1] += b[i] / a[i];
		b[i] %= a[i];
	}
	if (b[len + 1]) { len++; }
	for (int i = len;  i >= 2; i--) {
		printf("%d,", b[i]);
	}
	printf("%d", b[1]);
}