#include <cstring>
#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	char a[260];
	cin.getline(a,255);
	int len = strlen(a);int num = 0;
	for (int i = 0; i <= len; i++) {
		if ('0' <= a[i] and a[i] <= '9') { num++; }
	}
	printf("%d", num);
}