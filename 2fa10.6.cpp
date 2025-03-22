#include <iostream>
using namespace std;
int main() {
	char a[260];
	cin >> a;
	for (int i = 0; a[i] != '\0';) {
		if (a[i] == 'A') { a[i] = 'T'; }
		else if (a[i] == 'T') { a[i] = 'A'; }
		else if (a[i] == 'C') { a[i] = 'G'; }
		else if (a[i] == 'G') { a[i] = 'C'; }
		i++;
	}
	cout << a;
}