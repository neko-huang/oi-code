#include <iostream>
using namespace std;
bool check[1010];
int abs(int a) { return a >= 0 ? a : -a;}
int main() {
	int n,be=0,no=0;
	cin >> n;
	cin >> no;
	for (int i = 1; i <= n - 1; i++) {
		be = no;
		cin >> no;
		if(abs(no-be)<1010)
			check[abs(no - be)] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (!check[i]) { cout << "Not jolly"; return 0; }
	}
	cout << "Jolly"; return 0;
}