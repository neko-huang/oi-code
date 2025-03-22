#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n,temp,sum=0; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		if (temp % 2 == 0) { sum += temp; }
	}
	printf("%d", sum);
}
