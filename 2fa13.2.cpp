#include <iostream>
using namespace std;
#define max 2333
char a[max], b[max]; int a1[max], b1[max], c[max * 2];
int len(char a[]) {
	int i = 0;
	for (; a[i] != '\0'; i++) {}
	return i - 1;
}
int main() {
	cin >> a >> b;
	int lena = len(a),lenb=len(b);
	int leng = lena + lenb+1;
	for (int i = 0; i <= lena; i++) {
		a1[i] = a[lena - i] - '0';
	}
	for (int i = 0; i <= lenb; i++) {
		b1[i] = b[lenb - i] - '0';
	}
	for (int i = 0; i <= lena; i++) {
		for(int p=0;p<= lenb;p++){
			c[i + p] += a1[i] * b1[p];
		}
	}
	for (int i = 0; i <= leng; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while (!c[leng] && leng) { leng--; }
	for (int i = leng; i >= 0; i--) {
		printf("%d", c[i]);
	}
}