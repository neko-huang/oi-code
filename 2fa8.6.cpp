#include <iostream>
using namespace std;
char l[105];
int main() {
	cin >> l;
	int i = 0;
	while (l[i] != '\0') {
		l[i]-= ('a' <= l[i] and l[i] <= 'z') ?  32 : 0;
		i++;
	}
	cout << l;
}