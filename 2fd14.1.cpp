#include <iostream>
using namespace std;
#pragma warning (disable:4996)
void in(int& a) {
	scanf("%d", &a);
	return;
}
void out(int& a) {
	printf("%d", a);
	return;
}
int main() {
	int farm[5005], tmp;
	int m;
	in(m);
	for (int i = 1; i <= m; i++) {
		in(farm[i]);
	}
	bool flag;
	for (int i = 1; i <= m; i++) {
		flag = 0;
		for (int p = 1; p <= m - i; p++) {
			if (farm[i] > farm[i + 1]) {
				tmp = farm[i]; farm[i] = farm[i + 1]; farm[i + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag) { break; }
	}
	for (int i = 1; i <= m; i++) {
		out(farm[i]); cout << ' ';
	}
}