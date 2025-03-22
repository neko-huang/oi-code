#include <iostream>
using namespace std;
int main() {
	double a; char DNA1[600], DNA2[600];int  sum=0, num=0;
	cin >> a >> DNA1 >> DNA2;
	for (int i = 0; DNA1[i] != '\0';) {
		if (DNA1[i] == DNA2[i]) {
			sum++;
		}
		num++;
		i++;
	}
	double bsum = sum, bnum = num;
	if (bsum / bnum >= a) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}