#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = int(2e5 + 5);
set <int> reca[maxn];
bool recb[maxn];

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
	int n = read(), m = read(), q = read();
	for (int i = 1; i <= q; i++) {
		int opt = read();
		if (opt == 1) {
			int x = read(), y = read();
			reca[x].insert(y);
		}
		else if (opt == 2) {
			int x = read();
			recb[x] = 1;
		}
		else {
			int x = read(), y = read();
			if (recb[x] or reca[x].find(y)!=reca[x].end()) {
				printf("Yes\n");
				continue;
			}
			printf("No\n");
			
		}
	}
	return 0;
}