#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string t, u;
	cin >> t >> u;
	for (int i = 0; i <= t.length() - u.length(); i++) {
		bool flag = 0;
		for (int j = 0; j < u.length(); j++) {
			if (t[i+j]!='?' and t[i + j] != u[j]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}