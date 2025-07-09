#include <iostream>
using namespace std;

const int maxn = int(2e3 + 5);
bool maze[maxn][maxn];

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}

int main() {
	int n = read();
	while (n--) {
		int x = read(), y = read();
		maze[x + 1000][y + 1000] = 1;
		maze[x + 1001][y + 1000] = 1;
		maze[x + 1000][y + 1001] = 1;
		maze[x + 1001][y + 1001] = 1;
	}
	int ans = 0;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			if (maze[i][j]) {
				ans++;
			}
		}
	}
	cout << ans;
}