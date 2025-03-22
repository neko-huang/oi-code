#include <stdio.h>
using namespace std;
#pragma warning(disable:4996)
#define maxn 100000000
int pri[maxn]; 
int main() {
	int n,len=1,flag;
	scanf("%d", &n);
	pri[1] = 2;
	for (int i = 3; i <= n; i++) {
		flag = 0;
		for (int o = 1; pri[o]<= i/pri[o]; o++) {
			if (i % pri[o] == 0) {
				flag = 1; break;
			}
		}
		if (flag == 1) { continue; }
		pri[++len] = i;
	}
	for (int i = 1; i <= len; i++) {
		printf("%d\n", pri[i]);
	}
}