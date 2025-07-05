#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 105;
string list[maxn];
vector <string> uq;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> list[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				uq.push_back(list[i] + list[j]);
			}
		}
	}
	sort(uq.begin(), uq.end());
	uq.erase(unique(uq.begin(), uq.end()), uq.end());
	cout << uq.size();
}