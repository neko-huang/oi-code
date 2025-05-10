#include <iostream>
#include <string.h>

using namespace std;
const int maxl = int(1e6 + 5);

int nxt[maxl];

void get_nxt(string s) {
	for (int i = 1, j = 0; i < s.length(); i++) {
		if (s[i] != s[j] and j) {
			j = nxt[j - 1];
		}
		if (s[i] == s[j]) {
			nxt[i] = ++j;
		}
	}
}

int search(string s, string p) {
	for (int i = 1, j = 0; i < s.length(); i++) {
		if (s[i] != p[j] and j) {
			j = nxt[j - 1];
		}
		if (s[i] == p[j]) {
			j++;
		}
		if (j == p.length()) {
			return i - j + 1;
		}
	}
}
int main() {
	int L;
	cin >> L;
	string s1;
	cin >> s1;
	get_nxt(s1);
	int m_num = 0, m_dwn = 0;
	for (int i = 1; i <= L; i++) {
		if (m_num < nxt[i]) {
			m_dwn = i;
			m_num = nxt[i];
		}
	}
	printf("%d",L-nxt[L-1]);
}