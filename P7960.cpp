#include <iostream>

using namespace std;


const int maxn = int(1e7 + 5);
bool can[maxn];
int tmp;
int nxt[maxn];

bool has7(int n) {
	if (n % 7 == 0) {
		return 1;
	}
	while (n) {
		if (n % 10 == 7) {
			return 1;
		}
		n /= 10;
	}
	return 0;
}

void sleve() {
	for (int i = 1; i <= maxn; i++) {
		if (can[i]) {
			continue;
		}
		if (has7(i)) {
			for (int j = 1; j * i <= maxn; j++) {
				can[j * i] = 1;
			}
			continue;
		}
		nxt[tmp] = i;
		tmp = i;
	}
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
	sleve();
	int T = read();
	while (T--) {
		int n = read();
		if (can[n]) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",nxt[n]);
	}
}