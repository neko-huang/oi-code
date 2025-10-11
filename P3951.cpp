#include <iostream>

using namespace std;

void exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= a / b * x;
	return;
}

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1 ;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt* sgn;
} 

int main() {
	int a = read(), b = read();
	//int x, y;
	//exgcd(a, b, x, y);
	long long a1 = max(a, b), b1 = min(a, b);
	printf("%lld", ((b1 - 1) * (a1 - 1)-1));
	return 0;
}