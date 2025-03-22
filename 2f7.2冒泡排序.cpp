#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int a[10], temp; bool flag=0;
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &a[i]);
	}
	for (int p = 1; p <= 4; p++) {
		for (int i = 1; i <= 4-i; i++) {
			if (a[i] > a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) { break; }
		flag = 0;
	}
	for (int i = 1; i <= 4; i++) {
		printf("%d ", a[i]);
	}
}