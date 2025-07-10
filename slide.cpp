#include <iostream>

using namespace std;
typedef long long ll;
const long long maxn = int(1e6 + 5);
long long read(){
	long long igt = 0, sgn = 1;
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

long long a[maxn];

int main() {
	freopen("slide.in", "r", stdin);
	freopen("slide.out", "w", stdout);
	long long n = read(), k = read();
	for (long long i = 1; i <= n; i++) {
		a[i] = read();
	}
	long long sum = 0;
	long long ans = 0;
	for (long long l=1,r=n; l <= r; ) {
		while (sum + a[r] <= k and l<=r) {
			sum += a[r--];
		}
		while (sum + a[l] <= k and l <= r) {
			sum += a[l++];
		}
		sum = 0, ans++;
	}
	cout << ans;
	return 0;
}