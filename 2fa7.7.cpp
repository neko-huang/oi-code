#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main(){
	int n, l[1005],l1[1005],num,u;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
	}
	scanf("%d",&num);
	for (u = 1; true; u++) {
		if (num < l[u]) {
			l1[u] = num;
			break;
		}
		l1[u] = l[u];
	}
	for (; u <= n + 1; u++) {
		l1[u + 1] = l[u];
	}
	for (int i = 1; i <= n+1; i++) {
		printf("%d ", l1[i]);
	}
	return 0;
}