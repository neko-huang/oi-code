#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[10]; int CNT = 0;
	cin.getline(a, 10);
	for (int i = 0; i <= strlen(a); i++) {
		if (a[i] != ' ' and a[i]!='\0') { CNT++; }
	}
	printf("%d", CNT);
}