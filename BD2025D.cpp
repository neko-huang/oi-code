#include <iostream>


using namespace std;
const int maxn = int(1e5 + 5);

bool vis[maxn];
int n;
int ans = 0;
int rec[maxn];
int tmp[maxn];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void dfs(int x, int now) {
	if (x == n+1) {
		if (now > ans) {
			ans = now;
			for (int i = 1; i <= n; i++) {
				rec[i] = tmp[i];
			}
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tmp[x] = i;
			vis[i] = 1;
			dfs(x + 1, gcd(now, x * i));
			vis[i] = 0;
		}
	}
	return;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		tmp[1] = i;
		dfs(2, i);
		vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << rec[i] << ' ';
	}
}