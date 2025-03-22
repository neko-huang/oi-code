#include <iostream>
using namespace std;
int main() {
	double n[10], temp; int h, t,m;
	for (int i = 1; i <= 4; i++) {
		cin >> n[i];
	}
	for (int i = 2; i <= 4; i++) {
		temp = n[i]; h = 1; t = i - 1; 
		while (h <= t) {
			m = (h + t) / 2;
			if (temp < n[m]) { t = m - 1; }
			else { h = m + 1; }
		}
		for (int o = i - 1; o >= h; o--) { n[o + 1] = n[o]; }
		n[h] = temp;
	}
	for (int i = 1; i <= 4; i++) {
		cout << n[i]<<' ';
	}
}