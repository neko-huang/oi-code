#include <iostream>
using namespace std;
typedef long long ll ;
ll c[55];	
int main() {
	int n;
	cin >> n;
	c[1] = c[2]=c[3]=1;
	for (int i = 4; i <= n; i++) {
		c[i] = c[i - 3] * 2 + c[i - 1] - c[i - 3];
	}
	cout << c[n];
}