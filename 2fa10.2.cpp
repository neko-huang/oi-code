#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char c[114514]; int cnt[30] = {0};
	cin.getline(c, 114514);
	int len = strlen(c);
	for (int i = 0; i <= len; i++) {
		cnt[c[i] - 'a' + 1]++;
	}
	int big = 1;
	for (int i = 2; i <= 26; i++) {
		if (cnt[i] > cnt[big]) {
			big = i;
		}
	}
	printf("%c", big + 'a' - 1);
}