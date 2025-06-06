#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
const ll inf = 2147483647;
//const ll inf = LLONG_MAX;
ll dp[10][10];

ll min(ll a, ll b, ll c) {
    return min(a, min(b, c));
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;//000001111100000 
        dp[1][1] = 0;//ǰ���һ��0��                           s1
        dp[2][1] = inf;//ǰ�����һ���� ������1��               s2
        dp[3][1] = inf;//ǰ����һ�� 0 �� 1 ������ 0 ��          s3

        for (int i = 0; i < n; i++) {
            dp[1][2] = dp[1][1] + (s[i] == '1' ? 1 : 0);//��ǰ��'1' ���1 ��Ϊ Ҫ����һ��
            dp[2][2] = min(dp[1][1], dp[2][1]) + (s[i] == '0' ? 1 : 0);//������s1 s2�任//s1:����һ��0 s2:����һ��1 Ȼ���
            dp[3][2] = min(dp[2][1], dp[3][1]) + (s[i] == '1' ? 1 : 0);//������s2 s3 �任//s2:����һ��1 s3:����һ��0 Ȼ���
            dp[1][1] = dp[1][2];//upd
            dp[2][1] = dp[2][2];
            dp[3][1] = dp[3][2];
            
        }
        cout << min(dp[1][1], dp[2][1], dp[3][1]) << '\n';
    }
    return 0;
}