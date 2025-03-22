#include <iostream>
using namespace std;
int to[100000];
int tooth(int a) {
	if (to[a]) { return to[a]; }
	if (a == 1) { return to[a]=1; }
	if (a == 2) { return to[a]=2; }
	return to[a]=tooth(a - 1) + tooth(a - 2);
}
int main() {
	int n;
	cin >> n;
	cout << tooth(n);
}