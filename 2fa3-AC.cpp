#include <stdio.h>
using namespace std;
typedef long long ll;
bool prime(ll n) {
	for (int i = 2; i  <= n/i; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
ll n, k, cnt = 0; ll num[25];
void dfs(ll m,ll sum,ll now) {
	if (m == k) {
		if (prime(sum)==1)
			cnt++;
		return;
	}
	for (ll i = now; i < n; i++) {
		dfs(m + 1,sum+num[i], i+1);
	}
}
#pragma warning (disable:4996)
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &num[i]);
	}
	dfs(0,0,0);
	printf("%lld", cnt);
}