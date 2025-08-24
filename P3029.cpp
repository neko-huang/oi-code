#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = int(5e4 + 5);

struct node {
	int x, type;
}cow[maxn];

vector <int> tp;
int vis[maxn];
bool cmp(node a, node b) {
	return a.x < b.x;
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
	for (int i = 1; i <= n; i++) {
		cow[i].x = read(), cow[i].type = read();
		tp.push_back(cow[i].type);
	}
	sort(cow + 1, cow + 1 + n, cmp);

	sort(tp.begin(), tp.end());
	tp.erase(unique(tp.begin(), tp.end()), tp.end());
	int cnttp = tp.size();
	for (int i = 1; i <= n; i++) {
		cow[i].type = lower_bound(tp.begin(), tp.end(), cow[i].type) - tp.begin();
	}
	
	int l = 1, r = 0;
	int cnt = 0;
	int ans = 0x3f3f3f3f;
	for (; l <= n; l++) {
		while (cnt < cnttp and r<n) {
			r++;
			if (!vis[cow[r].type]) {
				cnt++;
			}
			vis[cow[r].type]++;
		}
		if (cnt == cnttp) {
			ans = min(ans, cow[r].x - cow[l].x);
		}
		
		vis[cow[l].type]--;
		if (!vis[cow[l].type]) {
			cnt--;
		}
		if (cnt < cnttp and r == n) {
			break;
		}
	}
	cout << ans;
	return 0;
}