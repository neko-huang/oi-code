#include <stdio.h>
using namespace std;
typedef long long ll;
bool prime [ll(10e8 + 100)];
void primesai(bool a[],ll n) {//0ÊÇ1²»ÊÇ
	a[0] = a[1]=1;
	for (ll i = 4; i <= n; i += 2) {
		a[i] = 1;
	}
	for (ll i = 3; i*i <= n; i+=2) {
		if (!prime[i]) {
			for (ll p = i * i; p <= n; p += i * 2) {
				prime[p] = 1;
			}
		}
	}
}
int n, k, cnt = 0;ll sum = 0; bool can[25]; int num[25];
void dfs(ll m) {
	if (m > k) {
		if(!prime[sum])
			cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!can[i]) {
			can[i] = 1;
			sum += num[i];
			dfs(m + 1);
			can[i] = 1;
			sum -= num[i];
		}
	}
}
#pragma warning (disable:4996)
int main() {
	primesai(prime, ll(10e8));
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%ld", &num[i]);
	}
	dfs(1);
	printf("%d", cnt);
}