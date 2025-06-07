#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string t, a;
	cin >> t >> a;
	for (int i = 0; i < n; i++) {
		if (t[i] == a[i] and t[i]=='o') {
			cout << "Yes"; return 0;
		}
	}
	cout << "No";
}