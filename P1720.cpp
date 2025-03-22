#include <iostream>
using namespace std;
int main() {
	double f1 = 0, f2 = 1,cup,ct;
	cin >> ct;
	if (ct == 0) {
		cout << "0.00";
		return 0;
	}
	for (int i = 1; i < ct; i++) {
		cup = f1; f1 = f2; f2 += cup;
	}
	printf("%.2lf", f2);
	return 0;
}