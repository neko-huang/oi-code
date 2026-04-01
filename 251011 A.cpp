#include <iostream>
#include <string.h>


using namespace std;

string a;

int main() {
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (i+1 != (a.length() + 1) / 2) {
			cout << a[i];
		}
	}
	return 0;
}