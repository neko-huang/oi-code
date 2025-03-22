#include <iostream>
using namespace std;
char s[1000]; int pm[100], s1[100], s2[100],b[101];
#pragma warning (disable:4996)
void prime(int a[], int b) {
	a[1] = 2;
	int cnt = 1; bool flag;
	for (int i = 3; i <= b; i++) {
		flag = 0;
		for (int p = 1; p <= cnt; p++) {
			if (i % a[p] == 0) {
				flag = 1; break;
			}
		}
		if (!flag) { a[++cnt] = i; }
	}
}
int main() {
	prime(pm, 100); int len1, len2,i;
	scanf("%s", s);
	for (i = 0, len1 = 1; 1;i++) {
		if (s[i] == '+') {
			break;
		}
		if (s[i] == ',') { len1++; continue; }
		s1[len1] *= 10;
		s1[len1] += s[i] - '0';
	}
	for (i++,len2 = 1; 1;i++) {
		if (s[i] == '\0') {
			break;
		}
		if (s[i] == ',') { len2++; continue; }
		s2[len2] *= 10;
		s2[len2] += s[i] - '0';
	}
	/*
	for (int o = len1 + 1; o >= 2;o--) {
		printf("%d,", s1[o]);
	}
	printf("%d\n", s1[1]);
	*/
	/*
	for (int o = len2 + 1; o >= 2; o--) {
		printf("%d,", s2[o]);
	}
	printf("%d\n", s2[1]);
	*/
	int len = len1 > len2 ? len1 : len2;
	for (i = 1; i <= len; i++) {	
		b[i] += s1[len1 - i + 1] + s2[len2 - i + 1];
	}
	for (i = 1; i <= len + 1; i++) {
		/*
		for (int o = len + 1; o >= 2;o--) {
			printf("%d,", b[o]);
		}
		printf("%d\n", b[1]);
		*/
		b[i + 1] += b[i] / pm[i];
		b[i] %= pm[i];
	}
	if (b[len + 1]) { len++; }
	for (i = len; i >= 2; i--) {
		printf("%d,", b[i]);
	}
	printf("%d", b[1]);
}