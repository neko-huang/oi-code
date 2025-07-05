#include <iostream>
#include <queue>
#include <utility>

using namespace std;
queue <pair<int, int>> Q;

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
	int q = read();
	while (q--) {
		int opt = read();
		if (opt == 1) {
			int c = read(), x = read();
			Q.push({ x,c });
		}
		else {
			long long ans = 0;
			int k = read();
			while (k > 0 && !Q.empty()) {
				auto& tmp = Q.front();
				if (tmp.second > k) {
					ans += (long long)k * tmp.first;
					tmp.second -= k;
					break;
				}
				else {
					ans += (long long)tmp.second * tmp.first;
					k -= tmp.second;
					Q.pop();
				}
			}
			cout << ans << '\n';
		}
	}
}