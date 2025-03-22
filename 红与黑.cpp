#include <iostream>
using namespace std;
char maze[22][22];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1c", &maze[i][j]);
		}
	}
}