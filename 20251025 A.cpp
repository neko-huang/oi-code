#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll maxn = 92;
ll xpos[maxn+5];
ll ypos[maxn+5];

ll read() {
	ll igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3)+ (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}

ll fib[maxn+5];

void init() {
	fib[1] = 1;
	for (ll i = 2; i < maxn; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	for (ll i = 1; i < maxn; i += 4) {
		xpos[i] = xpos[i + 1] = xpos[i + 3] = xpos[i - 1] - fib[i];
		xpos[i + 2] = xpos[i + 1] + fib[i + 1];
	}
	for (ll i = 2; i < maxn; i += 4) {
		ypos[i] = ypos[i + 1] = ypos[i + 3] = ypos[i - 1] - fib[i];
		ypos[i + 2] = ypos[i + 1] + fib[i + 1];
	}

	return;
}

int main() {
	
	

	ll T = read();
	init();

	while (T--) {
		ll tmpx=read(), tmpy=read();
		for (ll i = 1; i < 72; i++) {
			if (tmpx >= xpos[i] and tmpx- fib[i] <= xpos[i] ) {
				if (tmpy >= ypos[i] and tmpy- fib[i] <= ypos[i] ) {
					cout << fib[i];
					cout << '\n';
					break;
				}
			}
		}
	}
	return 0;
}