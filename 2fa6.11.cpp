#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n,flag=0,sum=0; scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		flag = 0;
		for (int o = 2; o <= i / o; o++) {
			if (i % o == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) { sum++; }
	}
	printf("%d", sum);
}
