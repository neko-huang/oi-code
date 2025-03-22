#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[90], b[90];
	cin.getline(a, 80);
	cin.getline(b, 80);
	for (int i = 0; i < strlen(a); i++) {
		if ('A' <= a[i] and a[i] <= 'Z') {
			a[i] -= 'A'-'a';
		}
	}
	for (int i = 0; i < strlen(b); i++) {
		if ('A' <= b[i] and b[i] <= 'Z') {
			b[i] -= 'A' - 'a';
		}
	}
	if (strcmp(a, b) > 0) {
		cout << '>';
	}
	else if (strcmp(a, b) == 0) {
		cout << '=';
	}
	else if(strcmp(a,b)<0){
		cout << '<';
	}
}