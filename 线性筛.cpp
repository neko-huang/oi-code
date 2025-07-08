#include <iostream>
#include <vector>
using namespace std;

const int maxn = int(1e6 + 5);
vector <int> prime;
bool isprime[maxn];

void E_s(int n){
	isprime[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!isprime[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() and i*prime[j] <= n; j++) {
			isprime[i * prime[j]] = 1;
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
	E_s(n);
	for (int i = 0; i < prime.size(); i++) {
		cout << prime[i] << ' ';
	}
	return 0;
}