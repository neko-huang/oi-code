#include <iostream>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int base = 1;
	int ans = 1;
	for (int i = 1; i <= m; i++) {
		base *= n;
		ans += base;
		if (ans > int(1e9) or ans < 0) {
			printf("inf");
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}