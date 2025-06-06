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
        dp[1][1] = 0;//前面的一段0里                           s1
        dp[2][1] = inf;//前面加有一段零 现在在1里               s2
        dp[3][1] = inf;//前面有一段 0 和 1 现在在 0 里          s3

        for (int i = 0; i < n; i++) {
            dp[1][2] = dp[1][1] + (s[i] == '1' ? 1 : 0);//当前是'1' 则加1 因为 要更换一下
            dp[2][2] = min(dp[1][1], dp[2][1]) + (s[i] == '0' ? 1 : 0);//可以由s1 s2变换//s1:脱离一堆0 s2:继续一堆1 然后加
            dp[3][2] = min(dp[2][1], dp[3][1]) + (s[i] == '1' ? 1 : 0);//可以由s2 s3 变换//s2:脱离一堆1 s3:继续一堆0 然后加
            dp[1][1] = dp[1][2];//upd
            dp[2][1] = dp[2][2];
            dp[3][1] = dp[3][2];
            
        }
        cout << min(dp[1][1], dp[2][1], dp[3][1]) << '\n';
    }
    return 0;
}