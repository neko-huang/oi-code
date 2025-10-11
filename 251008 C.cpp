#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;


const int maxn = 17;

ll dp[maxn][(1 << maxn) + 5];

struct pos {
	ll x, y, z;
};
pos city[maxn];
ll cost[maxn][maxn];

/*ll abs(ll x) {
	return x > 0 ? x : -x;
}*/

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll value(pos first, pos second) {
	ll dx = abs(first.x - second.x);
	ll dy = abs(first.y - second.y);
	ll dz = max(second.z - first.z, 0);
	return dx + dy + dz;
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

	memset(dp, 0x3f, sizeof(dp));

	ll n = read();
	for (int i = 0; i < n; i++) {
		city[i].x = read(), city[i].y = read(), city[i].z = read();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cost[i][j] = value(city[i], city[j]);
		}
	}
	dp[0][1] = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < (1 << n); j++) {
			if (!(j & (1 << i)))continue;
			for (ll k = 0; k < n; k++) {
				if (k == i)continue;
				if (!(j & (1 << k)))continue;
				dp[i][j] = min(dp[i][j],min(dp[k][(j^(1<<i))],dp[k][j])+cost[k][i]);
			}
		}
	}
	for (ll i = n-1; i >= 0; i--) {
		for (ll j = 0; j < (1 << n); j++) {
			if (!(j & (1 << i)))continue;
			for (ll k = 0; k < n; k++) {
				if (k == i)continue;
				if (!(j & (1 << k)))continue;
				dp[i][j] = min(dp[i][j], min(dp[k][(j ^ (1 << i))], dp[k][j]) + cost[k][i]);
			}
		}
	}
	cout << dp[0][(1 << n)  - 1];
}