#include <iostream>
using namespace std;
int main() {
	char s[105];
	cin.getline(s, 100);
	for (int i = 0; s[i] != '\0'; i++) {
		if ('a' <= s[i] && 'z' >= s[i]) {
			s[i] += 4;
		}
		if ('A' <= s[i] && 'Z' >= s[i]) {
			s[i] += 4;
		}
		if (!('A' <= s[i] && 'Z' >= s[i]) && !('a' <= s[i] && 'z' >= s[i])) {
			s[i] -= 26;
		}
	}
	printf("%s", s);
}