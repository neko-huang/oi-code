#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = int(2e4 + 5);

struct node {
	short v;
	int w;
};
vector <node> G[maxn];
int cnt;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void dfs(int x,int fx,int dis){
	if (dis % 3 == 0) {
		cnt++;
	}
	for (int i = 0; i < G[x].size(); i++) {
		if (G[x][i].v == fx) {
			continue;
		}
		dfs(G[x][i].v, x, (dis+G[x][i].w)%3);
	}
	return;
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
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}

int main() {

	int n = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(), w = read();
		w %= 3;
		G[u].push_back({ short(v), w });
		G[v].push_back({ short(u), w });
	}

	for (int i = 1; i <= n; i++) {
		dfs(i,0,0);
	}

	int base = n * n;
	int hua = gcd(base, cnt);
	base /= hua; cnt /= hua;
	cout << cnt << '/' << base;
	return 0;
}