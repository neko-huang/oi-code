#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;
int main() {
	int n; char c[10000]; int t[27] = { 0 };
	scanf("%d%s", &n,&c);
	int len = strlen(c);
	for (int i = 0; i <= len; i++) {
		if ('A' <= c[i] and c[i] <= 'Z') {
			t[c[i] - 'A' + 1]++;
			continue;
		}
		if ('a' <= c[i] and c[i] < +'z') {
			t[c[i] - 'a' + 1]++;
			continue;
		}
	}
	for (int i = 1; i <= 26; i++) {
		if (t[i] == 0) { continue; }
		printf("%c:%d\n", i + 'a' - 1, t[i]);
	}
}