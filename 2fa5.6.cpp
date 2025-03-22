#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n,flag=0; scanf("%d", &n);
	for (int i = 2; n != 1; i++) {
		for (int a = 2; a < i / a; a++) {
			if (i % a == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) { flag = 0; break; }
		while (n % i == 0) {
			printf("%d", i);
			n /= i;
			if (n != 1) { printf("*"); }
		}
	}
	return 0;
}