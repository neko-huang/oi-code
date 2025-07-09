#include <iostream>
#include <string.h>
using namespace std;

long long f(long long x) {
	return (x + 1) * (x) / 2;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long t;
	cin >> t;
	while (t--) {
		long long n,ans=0;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		long long cnt = 0;
		for (long long i = 0; i < n; i++) {
			if (s1[i] == s2[i] and s1[i]=='1') {
				cnt++;
			}
			else {
				ans += f(cnt);
				cnt = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}