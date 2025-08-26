//abd415E
/*
2*10^5*10^9=2^10^14
Ӳ�ҵķ�Χ[0,2e14]�����ִ�
dp[i][j] ����(i,j)ʣ���Ӳ��������-1��������
dp[i][j]+(i,j) �жϣ��ܷ������ʳ��
����𣬼��������𷵻�
O(h*w*logv)
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, p[200005];
vector<vector<int> >A;
vector<vector<int> >dp;//dp[i][j]����(i,j)ʣ�������Ӳ��
bool check(int money) {
	dp = vector<vector<int> >(n + 1, vector<int>(m + 1, -1));
	dp[1][1] = money;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == -1) continue;
			dp[i][j] += A[i][j];
			int k = i + j - 1;//�ߵ�(i,j)���˶�����
			if (dp[i][j] < p[k]) {
				dp[i][j] = -1;
				continue;
			}
			dp[i][j] -= p[k];
			if (i + 1 <= n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + 1 <= m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
		}
	}
	return dp[n][m] != -1;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	A = vector<vector<int> >(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	for (int i = 1; i <= n + m - 1; i++) cin >> p[i];
	int l = 0, r = 2e14 + 1;
	while (l <= r) {//logv
		int mid = (l + r) >> 1;
		if (check(mid)) {//(n*m)
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}