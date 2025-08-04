#include <iostream>

using namespace std;
const int maxn = int(2e5 + 5);

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
	int first = read(), final = read();
	int cost = read(), sum = read();
	sum /= cost;
	if (final == first) {
		cout << "0";
		return 0;
	}
	if (final > first){
		if (final > first + sum) {
			cout << "-1";
			return 0;
		}
		else {
			cout << (final - first) * cost;
		}
	}


}