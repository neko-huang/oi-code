#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int ziran[15],cnt;
void out(int a[],int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void dfs(int g,int n,bool check) {//可放的克数,第几种
	if (g < 0) { return; }
	if (n == 11 && g > 0) { return; }
	if (n == 11) { 
		cnt++;
		if(check)out(ziran, 10);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		ziran[n] = i;
		dfs(g - i, n + 1,check);
		ziran[n] = 0;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	dfs(n, 1,0);
	if (cnt == 0) { printf("0"); return 0; }
	printf("%d\n", cnt);
	dfs(n, 1, 1);
}