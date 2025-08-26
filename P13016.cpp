#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = int(1e3 + 5);
const int inf = (0x3f3f3f3f);

bool isprime[inf];
vector <int> prime;

void get_prime(int n) {
	isprime[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) {
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() and i*prime[j]<=n; j++) {
			isprime[i * prime[j]] = 1;
			if (!(i % prime[j])) {
				break;
			}
		}
	}
	return;
}

vector <int> first;
vector <int> second;

void broke(int a,int b) {
	first.clear();
	second.clear();
	first.push_back(a);
	second.push_back(b);

	for (int i = 2; a != 1; i++) {
		while (a % i == 0) {
			a /= i;
			first.push_back(a);
		}
	}
	for (int i = 2; b != 1; i++) {
		while (b % i == 0) {
			b /= i;
			second.push_back(b);
		}
	}
	return;
}

int find() {
	int l = 0, r = 0;
	int lenl = first.size();
	int lenr = second.size();
	while (l < lenl and r < lenr) {
		if (first[l] < second[r]) {
			r++;
		}
		else if (first[l] > second[r]) {
			l++;
		}
		else {
			return l + r;
		}
	}
	return -1;
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
	int n = read();
	for (int i = 1; i <= n; i++) {
		int a = read(), b = read();
		broke(a, b);
		cout << find();
		cout << '\n';
	}
	return 0;
}