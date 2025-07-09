#include <iostream>

using namespace std;
const int maxn = int(1e5 + 5);

struct Pos {
	int x, y;
};
Pos a[maxn];
int sqrt(int x) {
	return x * x;
}
int Two_Point(Pos a, Pos b) {
	return sqrt(a.x - b.x) + sqrt(a.y - b.y);
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
	int n=read();
	for (int i = 1; i <= n; i++) {
		int tmpx = read(), tmpy = read();
		a[i] = { tmpx,tmpy };
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			ans += Two_Point(a[i], a[j]);
		}
	}
	cout << ans;
	return 0;
}