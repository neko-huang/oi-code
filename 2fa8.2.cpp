#include <iostream>
#include <cstring>
using namespace std;
char a[5][25];
int main() {
	int big = 1;
	cin>>a[1]>>a[2]>>a[3];
	for (int i = 2; i <= 3; i++) {
		if (strlen(a[i]) >= strlen(a[big])) {
			big = i;
		 }
	}
	cout << a[big] << '\n'<<strlen(a[big]);
}