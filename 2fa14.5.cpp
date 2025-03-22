#include <iostream>
using namespace std;
char a1[5141]; long long b,a[5141];
#pragma warning (disable:4996)
int lenstring(char a[]) {
	int len=0;
	while(a[++len]!='\0'){}
	return len - 1;
}
int main() {
	scanf("%s%lld", a1, &b);
	int len = lenstring(a1);
	for (int i = 0; i <= len; i++) {
		a[i] = a1[i]-'0';
	}
	for (int i = 0; i <= len; i++) {
		if (a[i] / b == 0) {
			if(i<len)a[i + 1] += a[i] * 10;
			a[i] = 0;
			continue;
		}
		if (i<len)a[i + 1] += (a[i] % b) * 10;
		a[i] -= a[i] % b;
		a[i] /= b;
	}
	int front = 0;
	while (!a[front] && front < len) { front++; }
	for (; front <= len; front++) {
		printf("%lld", a[front]);
	}
	return 0;
}