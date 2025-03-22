#include <iostream>
using namespace std;
int main() {
	long long n, temp,i=1,og;
	cin >> n;
	while (i <= n) {
		temp = 0;
		o = i-1;
		while (o >= 1) {
			if (i % o == 0) { temp += o; }
			o--;
		}
		if (temp == i) { printf("%lld\n", i); }
		i++;
	}
	return 0;
}