#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 12;
const int mod = 10000007;

int ans[maxn];
int mal[maxn][maxn];
int n, m;

void mul(int a[maxn], int b[maxn][maxn], int l) {
	int c[maxn];
	memset(c, 0, sizeof(c));
	for (int i = 0; i <= l+1; i++) {
		for (int j = 0; j <= l+1; j++) {
			c[i] += a[j] * b[i][j];
			c[i] %= mod;
		}
	}
	for (int i = 0; i <= l+1; i++) {
		a[i] = c[i];
	}
	return;
}

void mul(int a[maxn][maxn],int l) {
	int b[maxn][maxn];
	memset(b, 0, sizeof(b));
	for (int i = 0; i <= l + 1; i++) {
		for (int j = 0; j <= l + 1; j++) {
			for (int k = 0; k <= l + 1; k++) {
				b[i][j] += b[i][k] * b[k][j];
				b[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i <= l + 1; i++) {
		for (int j = 0; j <= l + 1; j++) {
			a[i][j] = b[i][j];
		}
	}
	return;
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
	while (scanf("%d%d", &n, &m) != 'EOF') {
		for (int i = 0; i <= n; i++) {
			mal[0][i] = 10;
		}
		for (int i = 0; i <= n + 1; i++) {
			mal[n + 1][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				mal[i][j] = 1;
			}
		}
		ans[0] = 233;
		ans[n + 1] = 3;
		for (int i = 1; i <= n; i++) {
			ans[i] = read();
		}

	}
}