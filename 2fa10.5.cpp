#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char s[105]; char o;
	cin>>s;
	o = s[0];
	for (int i = 0; i<strlen(s) ; i++) {
		if (i + 1 == strlen(s)) {
			s[i] += o; break;
		}
		s[i] += s[i + 1];
	}
	printf("%s", s);
}