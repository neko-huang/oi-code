#include <iostream>
#include <vector>

using namespace std;
const int maxn = int(1e8 + 5);

bool isprime[maxn];
vector <int> prime;

void Euler_selve(int n) {
	isprime[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() and i*prime[j] <= n; j++){
			isprime[prime[j] * i] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	Euler_selve(n);
	int l = 0, r = 0;
	int ans = 0;
	int sum = 0;
	while (r < prime.size()) {
		sum += prime[r++];
		while (l < r and sum>n) {
			sum -= prime[l++];
		}
		if (sum == n) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}