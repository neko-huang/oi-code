#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n,list[105],num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	scanf("%d", &num);
	for (int i = 1; i <= n; i++) {
		if (list[i] % num == 0 or list[i] / 10 == num or list[i] % 10 == num) {
			printf("%d\n", list[i]);
		}
	}
	return 0;
}