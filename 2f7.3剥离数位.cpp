#include <iostream>
using namespace std;
int main() {
	int a, la[15] = {0},len;
	cin >> a;
	for (len=1; a != 0; a /= 10) {
		la[len++] = a % 10;
	}
	for (; len >= 1; len--) {
		if (la[len] == 0) {
			continue;
		}
		printf("%d", la[len]);
	}
	return 0;
}