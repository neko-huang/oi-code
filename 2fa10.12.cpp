#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	char a[105], b[105];
	int n;
	scanf("%d%s%s",&n,&a,&b);
	for (int i = 0; i < n; i++) {
		if (b[i] > a[i]) {
			printf("-1"); return 0;
		}
	}
	printf("%s", b);
}