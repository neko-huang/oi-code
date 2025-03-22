#include<iostream>
using namespace std;
int a[11451400] = { 0 }, ct; long long len = 0;
void logpow(long long l) {
	cin >> ct;
	a[0] = 1;
	int temp;
	for (int i = 1; i <= l; i++) {
		if (a[len] > 4) {
			len++;
		}
		for (long long o = len; o >= 0; o--) {
			a[o] *= 2;
		}
		for (int o = 0; o <= len; o++) {
			temp = a[o] / 10;
			a[o + 1] += temp;
			a[o] %= 10;
		}
		printf("%d ",i);
		for (long long o = len; o >= 0; o--) {
			printf("%d", a[o]);
		}
		cout << '\n';
	}
	return ;
}
void pow(long long l) {
	a[0] = 1;
	int temp;
	for (int i = 1; i <= l; i++) {
		if (a[len] > 4) {
			len++;
		}
		for (long long o = len; o >= 0; o--) {
			a[o] *= 2;
		}
		for (int o = 0; o <= len; o++) {
			temp = a[o] / 10;
			a[o + 1] += temp;
			a[o] %= 10;
		}
	}
	for (int o = len; o >= 0; o--) {
		printf("%d", a[o]);
	}
	return;
}
/*void numset(int a[], long long num, long long len) {
	for (int i = 0; i <= len; i++) {
		a[i] = num;
	}
	return ;
}*/
int main() {
	int a; cin >> a;
	pow(a);
	return 0;
}

