#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 2; i < n/i; i++) {
		if (n % i == 0) { printf("F"); return 0; }
	}
	printf("T"); return 0;
}