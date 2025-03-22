#include <iostream>
#include <cstring>
using namespace std;
char a[10000], b[10000],c[10000];
int main() {
	int n; cin >> n;
	cin >> a >> b;
	int lena = strlen(a),lenb=strlen(b);
	int len =  lena>lenb  ? lena : lenb;
	for (int i = 0; i < lena; i++) {
		if ('A' <= a[i] && a[i] <= 'Z') { c[lena - i - 1] += a[i] - 'A'+10; }
		else { c[lena - i - 1] += a[i]-'0'; }
	}
	for (int i = 0; i < lenb; i++) {
		if ('A' <= b[i] && b[i] <= 'Z') { c[lenb - i - 1] += b[i] - 'A' + 10; }
		else { c[lenb - i - 1] += b[i] - '0'; }
	}
	for (int i =0; i < len; i++) {
		c[i + 1] += c[i] / n;
		c[i]%=n;
		if (c[i] >= 10) { c[i] += 'A'-10; }
		else { c[i] += '0'; }
	}
	if (c[len]!=0) { 
		if (c[len] >= 10) { c[len] +=  'A'-10; }
		else { c[len] += '0'; }
		len++;
	}
	for (int i = len-1 ; i >= 0; i--) {
		cout << c[i];
	}
	return 0;
}