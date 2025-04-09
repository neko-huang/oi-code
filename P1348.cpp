#include <iostream>
using namespace std;
int ret(int x) {
	if (x % 4 == 0) {
		return 2;
	}
	if (x % 2 == 0) {
		return -1;
	}
	return 1;
}
int main() {
	int a, b;
	scanf("%d%d",& a, &b);
	int ans = 0;
	for (int i = a;i <= b;i++) {
		if (ret(i) != -1) {
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}