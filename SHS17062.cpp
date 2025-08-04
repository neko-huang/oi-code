#include <iostream>
#include <algorithm>

using namespace std;
const long long maxn = int(1e5 + 5);
long long dp[maxn];
long long a[maxn];

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

int main() {
	long long n = read();
	for (long long i = 1; i <= n; i++) {
		a[i] = read();
	}
	dp[1] = a[1];
	for (long long i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}
	cout << dp[n];
}