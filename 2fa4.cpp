#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
short cell[105][105], florr[105][105];
int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int n, m, cnt = 0;
void dfs(int x, int y) {
	int ax, ay;
	for (int i = 0; i <= 3; i++) {
		ax = x + dx[i]; ay = y + dy[i];
		if (!florr[ax][ay] and cell[ax][ay]) {
			florr[ax][ay] = cnt;
			dfs(ax, ay);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= m ; p++) {
			scanf("%1hd", &cell[i][p]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= m; p++) {
			if (!florr[i][p] and cell[i][p]) {
				cnt++;
				florr[i][p] = cnt;
				dfs(i, p);
			}
		}
	}
	printf("%d", cnt);
}