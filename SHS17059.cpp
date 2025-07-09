#include <iostream>
#include <algorithm>

using namespace std;
const long long maxn = int(1e5 + 5);

long long A[maxn];

long long read() {
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
signed main() {
	long long n = read(), c = read();
	for (long long i = 1; i <= n; i++) {
		cin >> A[i];
	}
	long long sum = 0;
	sort(A + 1, A + n + 1);
	for (long long l = 1, r = 1 , i = 1; i <= n; i++) {
		while (A[l] + c < A[i] and l <= n) {
			l++;
		}
		while (A[r] + c <= A[i] and r <= n) {
			r++;
		}
		if (A[i] - A[l] == c) {
			sum += (r - l);
		}
	}
	cout << sum;
	return 0;
}