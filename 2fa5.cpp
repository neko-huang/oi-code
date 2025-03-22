#include <iostream>
using namespace std;
#pragma warning (disable:4996)
char land[105][105]; short florr[105][105];
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
int dy[] = { -1,1,0,0,-1,-1,1,1 };
int n, m, cnt = 0;char tmp;
void dfs(int x, int y) {
	int ax, ay;
	for (int i = 0; i < 8; i++) {
		ax = x + dx[i]; ay = y + dy[i];
		if (florr[ax][ay] == 0 and land[ax][ay] == 'W') {
			florr[ax][ay] = cnt;
			dfs(ax, ay);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= m; p++) {
			scanf("%c", &tmp);
			if (tmp != '\n') {
				land[i][p] = tmp;
				continue;
			}
			scanf("%c", &tmp);
			land[i][p] = tmp;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 1; p <= m; p++) {
			if (florr[i][p] == 0 and land[i][p] == 'W') {
				cnt++;
				florr[i][p] = cnt;
				dfs(i, p);
			}
		}
	}
	/*
	printf("\n");
	for (int i = 1; i <= n; i++, printf("\n")) {
		for (int p = 1; p <= m; p++) {
			printf("%c",land[i][p]);
		}
	}
	printf("\n");
	for (int i = 1; i <= n; i++, printf("\n")) {
		for (int p = 1; p <= m; p++) {
			printf("%hd ", florr[i][p]);
		}
	}
	printf("\n");*/
	printf("%d", cnt);
}