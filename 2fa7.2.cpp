#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int high[15], len,ct=0;
	for (int i = 1; i <= 10; i++) {
		scanf("%d",&high[i]);
	}
	scanf("%d",&len);
	len += 30;
	for (int i = 1; i <= 10; i++) {
		if (len >= high[i]) {
			ct++;
		}
	}
	printf("%d", ct);
	return 0;
}