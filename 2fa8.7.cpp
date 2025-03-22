#include <iostream>
using namespace std;
unsigned char t[55];
int main() {
	int n;
	cin >> n >> t; n %= 26;
	int i = -1;
	while (t[++i] != '\0') {
		t[i] += n;
		while (t[i] > 'z') { t[i] -= 26; }
	}
	cout << t;
}