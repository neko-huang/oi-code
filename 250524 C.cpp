#include <iostream>

using namespace std;
const int mod = 10;
const int maxn = int(5e5 + 5);

long long f[maxn];
int main() {

	string s;
	cin >> s;

	for (int i = s.length()-1; i >= 0; i--) {
		f[i] = f[i + 1];
		f[i] += (((s[i] - '0' - f[i + 1]) % mod) + mod) % mod;
	}
	
	cout << f[0]+s.length();
	return 0;
}