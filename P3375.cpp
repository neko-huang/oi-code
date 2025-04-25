#include <iostream>
#include <string.h>
using namespace std;
const int maxn = int(1e6 + 5);
int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c < '0' or c>'9') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int nxt[maxn];
void getnxt(string s) {
	for (int i = 1, j = 0; i < s.length(); i++) {
		while (j and s[i] != s[j]) {
			j = nxt[j - 1];
		}
		if (s[i] == s[j]) {
			nxt[i] = ++j;
		}
	}
	return ;
}
int kmp(string s1, string s2) {//s1 text s2 search
	for (int i1 = 0, i2 = 0; i1 < s1.length(); i1++) {
		while (i2 and s1[i1] != s2[i2]) {
			i2 = nxt[i2 - 1];
		}
		if (s1[i1] == s2[i2]) {
			i2++;
		}
		if (i2 == s2.length()) {
			cout << i1 - i2 + 2<<'\n';//1+1 (i1-i2+1)+1
			i2 = nxt[i2-1];
		}
	}
	return -1;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	getnxt(s2);
	kmp(s1, s2);
	for (int i = 0; i < s2.length(); i++) {
		cout << nxt[i]<<' ';
	}
	return 0;
}