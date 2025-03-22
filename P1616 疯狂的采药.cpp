#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct yao {
	long long time=0, value=0,numb=0;
};
vector <yao> bao;
long long dp[10000007];
int main() {
	int t, m; yao tmp;
	cin >> t >> m;
	bao.push_back(tmp);
	for (int i = 1; i <= m; i++) {
		cin >> tmp.time >> tmp.value;
		tmp.numb = t / tmp.time;
		for (int p = 1; p <= tmp.numb+1; p*=2) {
			bao.push_back(tmp);
			tmp.time *= 2; tmp.value *= 2;
		}
	}
	size_t len = bao.size()-1;
	for (size_t i = 1; i <= len; i++) {
		for (int p = t; p >= bao[i].time; p--) {
			dp[p] = max(dp[p], dp[p - bao[i].time] + bao[i].value);
		}
	}
	cout << dp[t];
}
