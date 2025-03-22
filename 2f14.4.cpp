#include <iostream>
using namespace std;
void move(int n,int a,int b,int c) {
	if (n == 1) { cout << a << "-->" << c << '\n'; return; }
	move(n - 1, a, c, b);
	cout << a << "-->" << c<<'\n';
	move(n - 1, b, a, c);
}
int main() {
	int n;
	cin >> n;
	move(n, 1, 2, 3);
}