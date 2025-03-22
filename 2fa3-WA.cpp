#include <stdio.h>
#include <vector>
using namespace std;
vector <int> prime;
typedef long long ll;
bool sea(vector <int> a, int b) {//0 1 2 3 4 5
	int head = 0, tail = a.size() - 1, middle;
	while (head < tail) {
		middle = (head + tail) / 2;
		if (a[middle] < b) {
			head = middle + 1;
		}
		else {
			tail = middle - 1;
		}
	}
	if (a[head] == b) {
		return 1;
	}
	return 0;
}
void primesai(vector <int>& a, ll n) {
	a.push_back(2); bool flag = 0;
	for (int i = 3; i <= n; i++) {
		for (int p = 0; p < a.size(); p++) {
			if (i % a[p] == 0) {
				flag = 1; break;
			}
		}
		if (flag == 0)a.push_back(i);
		flag = 0;
		//printf("%d", i);
	}
}
ll n, k, cnt = 0, sum = 0; bool can[25]; ll num[25];
void dfs(ll m) {
	if (m > k) {
		if (sea(prime, sum))
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
	primesai(prime, k * 5000000);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num[i]);
	}
	dfs(1);
	printf("%lld", cnt);
}