#include <iostream>
#include <cstring>


using namespace std;

typedef long long ll;
const int maxn = int(2e5 + 5);


int buc[maxn];

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

int good[maxn];

int main() {
	int t = read();
	while (t--) {
		memset(buc, 0, sizeof(buc));
		int n = read(), y = read();
		for (int i = 1; i <= n; i++) {
			good[i] = read();
			buc[good[i]]--;
		}
	}
}