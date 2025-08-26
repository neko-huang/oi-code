/*
ABC415C-状压
 */
#include<iostream>

using namespace std;
int n;
char s[263000];
bool dp[263000]; // dp[i] 表示i这个状态是否能够安全获得

void solve() {
	cin >> n;
	cin >> (s + 1);

	dp[0] = true; // 空瓶子可以安全获得
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = false; // 假设当前状态不能安全获得
		if (s[i] == '1') // 危险状态，直接跳过
			continue;
		for (int j = 0; j < n; j++) // 枚举每一种化学物质
			if (i >> j & 1) // 如果i的2^j这一位上为1，表示i中存在第j种物质
				dp[i] |= dp[i ^ (1 << j)]; // 如果加入第j种物质之前的状态可以安全得到，则当前状态i也可以
	}

	if (dp[(1 << n) - 1] == true) // 检查所有物质均存在的状态是否能够安全得到
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
