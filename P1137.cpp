//topo + 单源最短路径

#include <iostream>
#include <vector>
#include 
using namespace std;
const int maxn = int(1e5 + 5);

int ind[maxn];
vector <int> G[maxn];

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

queue <int> bfs;
int main() {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		G[x].push_back(y);
		ind[y]++;
	}
	for(int )
}