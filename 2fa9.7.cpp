#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[10005];
	cin.getline(a, 10000);
	int len = strlen(a); int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] >= 'A' and a[i] <= 'Z') {
			a[i]-=5;
			if (a[i] <  'A') {
				a[i] += 26;
			}
		}
	}
	printf("%s", a);
}