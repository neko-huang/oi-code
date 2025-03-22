#include <iostream>
using namespace std;
int a,b,c ;
int f(int x) {
	return a * x * x + b * x + c;
}
int main() {
	cin >> a >> b >> c;
	char str[1005];
	cin >> str;
	int fors; cin >> fors;
	for (int i = 1; i <= fors; i++) {
		cout << str[f(i) - 1];
	}
}