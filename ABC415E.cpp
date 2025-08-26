#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxk = int(2e5 + 5);
const int inf = int(1e9 + 7);

vector <int> dp[maxk];
int h, w;
vector <int> maze[maxk];

void init() {
	for (int i = 0; i <= h+1; i++) {
		dp[i].clear();
		dp[i].resize(w+1);
	}
	return;
}

int solve(int n) {
	init();

	dp[1][1] = n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j]=dp[i][j]
		}
	}

}

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
	h = read(), w = read();

	for (int i = 1; i <= h; i++) {
		maze[i].resize(w);
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			maze[i][j] = read();
		}
	}



}