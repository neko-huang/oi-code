#include <iostream>
using namespace std;
typedef unsigned long long ll;
int check(int n, int m) {
	ll sum = 1,cnt=0;
	for (; n >= 2; n--) {
		sum *= n;
	}
	for (; sum != 0; sum /= 10) {
		if (sum % 10 == m) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	int  n,m,a;
	cin >> n;
	for (; n > 0; n--) {
		cin >> m >> a;
		cout << check(m, a)<<'\n';
	}
}