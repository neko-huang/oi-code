#include <iostream>
#include <cstring>
#pragma warning (disable:4996)	
void swap_s(char a[], char b[]) {
	char tmp[11451];
	std::cout << '-';
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}
void swap_i(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
using namespace std;
char a[11451], b[11451];int  ans[11451];
int main() {
	cin >> a >> b;
	int lena = strlen(a),lenb = strlen(b);
	if (lena < lenb) {
		swap_s(a, b); swap_i(lena, lenb);
	}
	else if (lena == lenb and strcmp(a, b) < 0) {
		swap_s(a, b); swap_i(lena, lenb);
	}
	else if (lena == lenb and strcmp(a, b) == 0) {
		cout << 0; return 0;
	}
	for (int i = 0; i < lena; i++) {
		ans[lena - i - 1] = a[i]-'0';
	}
	for (int i = 0; i < lenb; i++) {
		ans[lenb - i - 1] -= b[i]-'0';
	}
	int len = lena > lenb ? lena : lenb;
	for (int i = 0; i < len; i++) {
		while (ans[i] < 0) {
			ans[i + 1]--;
			ans[i] += 10;
		}
	}
	while (ans[len-1]==0) { len--; }
	for (int i = len-1 ; i >= 0; i--) {
		cout << ans[i];
		//cout << ans[i];
	}
}