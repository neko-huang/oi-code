#include <iostream>
using namespace std;
int main() {
	char s[40]; char a, b;
	cin >> s>>a>>b;
	for (int i = 0; s[i] != '\0';) {
		if (s[i] == a) { s[i] = b; }
		i++;
	}
	cout << s;
}