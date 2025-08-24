#include <iostream>
#include <queue>

using namespace std;
const int maxn = int(5e2 + 5);

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}

int slime[maxn][maxn];

struct pos {
	int x, y;
};

struct node {
	pos bounce;
	int energy;
	bool operator<(const node& other) {
		return energy < other.energy;
	}
};


priority_queue <node> bfs;

int main() {
	int h = read(), w = read(), x = read();
	int p = read(), q = read();
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			slime[i][j] = read();
		}
	}

	bfs.push({ {p,q},slime[p][q] });
}