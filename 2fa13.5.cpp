#include <iostream>
#include <cstring>
using namespace std;
char ticket[22][105];
bool cmp(char lei[], char tiao[]) {
	int lena = strlen(lei), lenb = strlen(tiao);
	if (lena < lenb) {
		return 0;
	}
	else if (lena == lenb && strcmp(lei, tiao) < 0) {
		return 0;
	}
	return 1;
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) { cin >> ticket[i]; }
	int max = 1;
	for (int i = 2; i <= n; i++) {
		if (cmp(ticket[max], ticket[i])==0) {
			max = i;
		}
	}
	cout << max <<'\n' << ticket[max];
}