#include <iostream>

using namespace std;
const long long mod = int(1e8 + 7);
const long long maxn = int(1e6 + 5);

long long A[maxn];
long long dp[maxn];

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

long long fpow(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b % 2) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

long long inv(long long a, long long b = mod - 2) {
	long long ans = 1;
	while (b) {
		if (b % 2) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return ans;
}

long long fac(long long x) {
	for (long long i = x-1; i >= 1; i--) {
		x *= i;
		x %= mod;
	}
	return x;
}

int main() {
	long long n=read(), m=read();
	long long tot = fpow(2, n) - 1;
	A[0] = 1;
	for (long long i = 1; i <= m; i++) {
		A[i] = A[i - 1] * ((tot - i + 1 + mod) % mod);
		A[i] %= mod;
	}
	dp[0] = 1;
	for (long long i = 2; i <= m; i++) {
		dp[i] = A[i];
		dp[i] -= dp[i - 1];
		dp[i] = ((dp[i] % mod) + mod) % mod;
		dp[i] -= dp[i - 2] * ((i - 1)%mod) * ((tot -i+ 2)%mod);
		dp[i] = ((dp[i] % mod) + mod) % mod;
	}
	cout << dp[m]*inv(fac(m))%mod;
}