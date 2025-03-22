#include <iostream>
using namespace std;
int main() {
	char a[1200]; int c[27] = {0},small=0;
	cin >> a;
	for (int i = 0; a[i] != '\0';) {
		c[a[i] - 'a' + 1]++;
		i++;
		for (int o = 1; o <= 26; o++) {
			if (c[small] == 1) { break; }
			if (c[o] == 1) { small = o; }
		}
	}
	if (c[small] != 1) { printf("no"); return 0; }
	printf("%c", small + 'a' - 1);
}