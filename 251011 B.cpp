#include <iostream>

using namespace std;

const int maxn = 105;
int num[maxn];

int buc(int x) {
	int ret = 0;
	while (x) {
		ret += (x % 10);
		x /= 10;
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	//cout << buc(1);
	num[0] = num[1] = 1;
	for (int i = 2; i <= n; i++) {
		num[i] = num[i-1] + buc(num[i-1]);
	}
	cout << num[n];
	return 0;
}