#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = int(3e3 + 5);

int A[maxn], B[maxn];
int dp[maxn][maxn];

int main() {
    int N, H, M;
    cin >> N >> H >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[0][H] = M;
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int h = 0; h <= H; h++) {
            if (dp[i-1][h] == -1) continue;

            if (h >= A[i]) {
                dp[i][h - A[i]] = max(dp[i][h - A[i]], dp[i-1][h]);
                ans = max(ans, i);
            }


            if (dp[i-1][h] >= B[i]) {
                dp[i][h] = max(dp[i][h], dp[i-1][h] - B[i]);
                ans = max(ans, i);
            }
        }
    }

    cout << ans ;
    return 0;
}
