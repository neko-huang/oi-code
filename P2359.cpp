#include <iostream>

using namespace std;
const int maxn = int(1e4 + 5);
const int mod = int(1e9 + 9);

bool isprime(int x) {
	if (x == 1 or !x) {
		return 0;
	}
	for (int i = 2; i * i <= x; i++) {
		if (!(x % i)) {
			return 0;
		}
	}
	return 1;
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
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int main() {
	int n=read();

}