#include <iostream>
#include <cstring>

using namespace std;

long long n, mod;

long long mart[2] = {0,1};

long long maul[2][2] = {
	{0,1},
	{1,1}
};

void mul(long long a[2], long long b[2][2]) {
	long long c[2];
	memset(c, 0, sizeof(c));
	for (long long i = 0; i <= 1; i++) {
		for (long long j = 0; j <= 1; j++) {
			c[i] += a[j] * b[i][j];
			c[i] %= mod;
		}
	}
	for (long long i = 0; i <= 1; i++) {
		a[i] = c[i];
	}
	return;
}

void mul(long long b[2][2]) {
	long long c[2][2];
	memset(c, 0, sizeof(c));
	for (long long i = 0; i <= 1; i++) {
		for (long long j = 0; j <= 1; j++) {
			for (long long k = 0; k <= 1; k++) {
				c[i][j] += b[i][k] * b[k][j];
				c[i][j] %= mod;
			}
		}
	}
	for (long long i = 0; i <= 1; i++) {
		for (long long j = 0; j <= 1; j++) {
			b[i][j] = c[i][j];
		}
	}
}

int main() {
	cin >> n >> mod;
	long long m = n + 2;
	while (m) {
		if (m & 1) {
			mul(mart, maul);
		}
		mul(maul);
		m /= 2;
	}
	n %= mod;
	mart[0] %= mod;
	mart[1] %= mod;
	mart[0] *= n;
	long long ans = mart[0] - mart[1] + 2;
	ans = (ans + mod) % mod;
	cout << ans;
	return 0;
}