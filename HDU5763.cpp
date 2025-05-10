#include <iostream>
#include <string.h>
#include <utility>
#include <set>

using namespace std;
const int maxn = int(1e5 + 5);
const int mod = 1000000007;

int nxt[maxn];

void get_nxt(string s) {
	for (int i = 1, j = 0; i < s.length(); i++) {
		if (j and s[i] != s[j]) {
			j = nxt[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
			nxt[i] = j;
		}
	}
}

int search(string s, string p) {
	set <int> place;
	int ans = 0;
	for (int i = 0, j = 0; i < s.length(); i++) {
		if (j and s[i] != p[j]) {
			j = nxt[j - 1];
		}
		if (s[i] == p[j]) {
			j++;
		}
		if (j == p.length()) {
			ans++;
			place.insert(i - j + 1);
			j = nxt[j - 1];
		}
	}
	for(int i)
	return ans;
}

int main() {
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		string s, p;
		cin >> s >> p;
		get_nxt(p);
		cout << "Case #" << i << ':' << search(s, p)+1 << '\n';
	}
	return 0;
}