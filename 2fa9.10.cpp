#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[90];
	cin.getline(a, 90);
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if ((a[i] >= 'a' and a[i] <= 'z') or (a[i] >= 'A' and a[i] <= 'Z')) {
			printf("%c", a[i]);
		}
	}
	
}