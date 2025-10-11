#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
const long long maxn = long long(3e3 + 5);

vector <long long> G[maxn];

double r[maxn];

struct pos {
	double x, y;
};
pos dot[maxn];

double dis(pos first, pos second) {
	double dx = first.x - second.x;
	dx *= dx;
	double dy = first.y - second.y;
	dy *= dy;
	double ret = sqrt(dx + dy);
	return ret;
}


long long read() {
	long long igt = 0, sgn = 1;
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
long long n;
void build_G() {
	for (long long i = 0; i < n + 1; i++) {
		for (long long j = i+1; j <= n + 1; j++) {
			double tmpdis = dis(dot[i], dot[j]);
			if (tmpdis <= r[i] + r[j] and tmpdis>=r[i] and tmpdis>=r[j]) {
				G[i].push_back(j);
				G[j].push_back(i);
				continue;
			}
			if (tmpdis < r[i] and r[i]>r[j]) {
				double tmp = r[i] - tmpdis;
				if (tmp <= r[j]) {
					G[i].push_back(j);
					G[j].push_back(i);
					continue;
				}
			}
			if (tmpdis < r[j] and r[j]>r[i]) {
				double tmp = r[j] - tmpdis;
				if (tmp <= r[i]) {
					G[i].push_back(j);
					G[j].push_back(i);
					continue;
				}
			}
		}
	}
	return;
}



long long vis[maxn];
long long flag = 0;

void dfs(long long now) {
	if (now == n + 1) {
		flag = 1;
		return;
	}
	if (flag) {
		return;
	}

	for (long long i = 0; i < G[now].size(); i++) {
		if (!vis[G[now][i]]) {
			vis[G[now][i]] = 1;
			dfs(G[now][i]);
			vis[G[now][i]] = 0;
		}
	}
	return;
}

int main() {
	n = read();

	dot[0].x = read(); dot[0].y = read(); dot[n + 1].x = read(); dot[n + 1].y = read();
	for (long long i = 1; i <= n; i++) {
		dot[i].x = read(), dot[i].y = read(), r[i] = read();
	}
	/*
	prlong longf("\n");
	*/
	build_G();
	/*
	for (long long i = 0; i <= n + 1; i++) {
		for (long long j = 0; j < G[i].size(); j++) {
			prlong longf("%d ", G[i][j]);
		}
		prlong longf("\n");
	}
	*/

	dfs(0);
	if (flag) {
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}