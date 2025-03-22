#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[1005];
	cin.getline(a, 1000);
	int len = strlen(a);
	for (int i = 0; i <= len; i++) {
		if (a[i] <= 'z' and a[i] >= 'a') {
			a[i]++;
			if (a[i] > 'z') {
				a[i] -= 26;
			}
		}
	}
	printf("%s", a);
}