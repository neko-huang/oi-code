#include <iostream>
using namespace std;
int main() {
	int n, m; long long sum=0;
	cin >> n >> m;
	while (n <= m) {
		sum += n;
		n++;
	}
	cout << sum;
	return 0;
}