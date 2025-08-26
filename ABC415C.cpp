/*
ABC415C-״ѹ
 */
#include<iostream>

using namespace std;
int n;
char s[263000];
bool dp[263000]; // dp[i] ��ʾi���״̬�Ƿ��ܹ���ȫ���

void solve() {
	cin >> n;
	cin >> (s + 1);

	dp[0] = true; // ��ƿ�ӿ��԰�ȫ���
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = false; // ���赱ǰ״̬���ܰ�ȫ���
		if (s[i] == '1') // Σ��״̬��ֱ������
			continue;
		for (int j = 0; j < n; j++) // ö��ÿһ�ֻ�ѧ����
			if (i >> j & 1) // ���i��2^j��һλ��Ϊ1����ʾi�д��ڵ�j������
				dp[i] |= dp[i ^ (1 << j)]; // ��������j������֮ǰ��״̬���԰�ȫ�õ�����ǰ״̬iҲ����
	}

	if (dp[(1 << n) - 1] == true) // ����������ʾ����ڵ�״̬�Ƿ��ܹ���ȫ�õ�
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
