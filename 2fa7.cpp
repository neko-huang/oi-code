#include <iostream>
#include <string.h>
using namespace std;
struct stu {
	string s; int y, m, d;
}a[105];
int cmp(stu a,stu b) {
	if (a.y > b.y) { return 0; }
	else if (a.y < b.y) { return 1; }
	else {
		if (a.m > b.m) { return 0; }
		else if (a.m < b.m) { return 1; }
		else {
			if (a.d > b.d) { return 0; }
			else if (a.d < b.d) { return 1; }
			else {
				return 2;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		 
	}
}