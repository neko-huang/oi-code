#include <stdio.h>
using namespace std;
bool num[100000000];
#pragma warning (disable:4996)
int main() {
	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i+=2) {
		num[i] = 1;
	}
	for (int i = 3; i <= n / i; i+=2) {
		if (num[i] == 0) {
			for (int o = i * i; o <= n; o += i*2) {
				num[o] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (num[i] == 0) { printf("%d\n", i); }
	}
	return 0;
}