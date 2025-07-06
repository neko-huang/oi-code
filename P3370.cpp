#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int base1 = int(1e9 + 7);
const int base2 = 139;
const int mod = int(1e9 + 9);

vector <int> h1;
vector <int> h2;
int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		int tmp1 = 0;
		int tmp2 = 0;
		for (int i = 0; i < s.length(); i++) {
			tmp1 = (tmp1 * base1) + s[i] - '0' + 1;
			tmp2 = (tmp2 * base2) + s[i] - '0' + 1;
		}
		h1.push_back(tmp1);
		h2.push_back(tmp2);
	}
	sort(h1.begin(), h1.end());
	sort(h2.begin(), h2.end());
	h2.erase(unique(h2.begin(), h2.end()), h2.end());
	h1.erase(unique(h1.begin(), h1.end()), h1.end());
	cout << min(h1.size(), h2.size());
	return 0;
}