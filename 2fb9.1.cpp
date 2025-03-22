#include <stdio.h>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n, t2; float t1; char t3[10];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%f%d%s", &t1, &t2, &t3);
		if (7 <= t1 and t1 <= 8 and t2 >= 1500 and strcmp(t3,"Yes")==0) {
			printf("Yes\n"); continue;
		}
		printf("No\n");
	}
	return 0;
}