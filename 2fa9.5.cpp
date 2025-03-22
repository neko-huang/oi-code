#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[205];
	cin.getline(a, 200);
	int len = strlen(a); int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == ' ') { cnt++; }
	}
	printf("%d", cnt);
}