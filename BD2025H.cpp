#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const long long maxn = int(2e5 + 5);

int a[maxn];
int b[maxn];
bool flag;
int read() {
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
	int T = read();
	while (T--) {
		flag = 0;
		int n = read(), x = read(), y = read();
		memset(a,0,sizeof(a));
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}

		int ans = 0;
		sort(a + 1, a + 1 + n);
		
		for (int i = 1; i <= n; i++) {
			b[i] = a[i] - a[i - 1];
		}

		int num = n;
		int cnt = 0;
		int now = 0;
		while(num){
			if (a[n] * x > num * y) {
				ans += num * y;
				cout << ans << '\n';
				flag = 1;
				break;
			}
			for (int i = 1; i <= n; i++) {
				if (a[i] == a[i + 1] and a[i] != 0) {
					cnt++; a[i] = 0;
					now = a[i];
				}
				else {
					break;
				}
			}
			for (int i = 1; i <= n; i++) {
				a[i] = max(a[i] - now, 0);
			}
			cnt++;
			num -= cnt;
			cnt = 0;
			ans += now * x;
			
		}
		if(!flag)cout << ans<<'\n';
	}

	return 0;
}