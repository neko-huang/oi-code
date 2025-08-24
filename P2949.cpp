#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
struct node {
	long long d, p;
};
const long long maxn = int(1e5 + 5);
bool cmp(node a, node b) {
	return a.d < b.d;
}

priority_queue< long long, vector<long long>, greater<int> > now;
node task[maxn];

long long read() {
	long long igt = 0, sgn = 1;
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
	long long n = read();
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		task[i].d = read(); task[i].p = read();
	}
	sort(task + 1, task + 1 + n, cmp);
	for (long long i = 1; i <= n; i++) {
		if (now.size() >= task[i].d) {
			if (task[i].p > now.top()) {
				ans = ans - now.top() + task[i].p;
				now.pop();
				now.push(task[i].p);
			}
		}
		else {
			ans += task[i].p;
			now.push(task[i].p);
		}
	}
	cout << ans;
	return 0;
}