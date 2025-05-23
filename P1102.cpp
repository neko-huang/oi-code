#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = int(2e5 + 5);

using ll = uint64_t;

ll lis[maxn];
std::map<ll, ll> num_cnt;

ll read() {
	ll igt = 0, sgn = 1;
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE


	ll n = read(), c = read();
	long long ans = 0;

	//memset(num_cnt, 0, sizeof(num_cnt));
	for (ll i = 1; i <= n; i++) {
		lis[i] = read();
		++num_cnt[lis[i]];
	}



	sort(lis + 1, lis + n + 1);
	n = std::unique(lis + 1, lis + n + 1) - (lis + 1);

	for (ll fir = 1, last = 2; last <= n;) {
		if (lis[last] < lis[fir] + c) { //区间差值小了 扩大区间 后移last索引
			last++;
		}
		if (lis[last] > lis[fir] + c) {
			fir++;
		}
		if (lis[last] == lis[fir] + c) {
			ans += num_cnt[lis[fir]] * num_cnt[lis[last]];
			fir++;
		}
	}
	cout << ans;
}