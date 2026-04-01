#include <iostream>
#include <vector>

using namespace std;

const int maxn = int(1e6 + 5);

bool node[maxn];

int dis[maxn][maxn];

struct info {
	int v, w;
};

vector <info> tree[maxn];

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c < '0' or c>'9') {
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

int main() {

	int n = read();
	
	for (int i = 1; i <= n; i++) {
		node[i] = read();
	}
	for (int i = 1; i < n; i++) {
		int tmpu = read(), tmpv = read(), tmpw = read();
		tree[tmpu].push_back({ tmpv,tmpw });
		tree[tmpv].push_back({ tmpu,tmpw });
	}	


}