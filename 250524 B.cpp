#include <iostream>

using namespace std;

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	double cnt=0;

	int x, y;
	cin >> x >> y;

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + j >= x or abs(i - j) >= y) {
				cnt += 1.0;
			}
		}
	}
	printf("%.10lf", double(cnt / double(36.0)));
	return 0;
}