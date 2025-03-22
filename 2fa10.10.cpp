#include <iostream>
using namespace std;
int n; char p1[10], p2[10]; int p1i, p2i;//P S R
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p1 >> p2;
		if (p1[0] == 'P') { p1i = 1; }
		else if (p1[0] == 'S') { p1i = 2; }
		else { p1i = 3; }
		if (p2[0] == 'P') { p2i = 1; }
		else if (p2[0] == 'S') { p2i = 2; }
		else { p2i = 3; }

		if (p1i == 3 and p2i == 1) { cout << "Player2\n"; }
		else if (p1i == 1 and p2i == 3) { cout << "Player1\n"; }
		else if (p1i < p2i) { cout << "Player2\n"; }
		else if (p1i > p2i) { cout << "Player1\n"; }
		else { cout << "Tie\n"; }
	}
}