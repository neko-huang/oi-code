#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = int(2e3 + 5);
int dp[maxn][maxn];
int read() {
    int igt = 0, sgn = 1;
    char c = getchar();
    while (c > '9' or c < '0') {
        if (c == '-') {
            sgn = -1;
        }
        c = getchar();
    }
    while (c <= '9' and c >= '0') {
        igt = (igt << 3) + (igt << 1) + c - '0';
        c = getchar();
    }
    return igt * sgn;
}
int a[maxn], b[maxn];
int max(int a, int b, int c) {
    return max(a, max(b, c));
}
bool cmp(int x, int y) {
    return x > y;
}
int cg(int x, int y) {
    if (a[x] > b[y]) {
        return 200;
    }
    else if (a[x] == b[y]) {
        return 0;
    }
    else {
        return -200;
    }
}
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] > b[j]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 200, dp[i - 1][j]-200, dp[i][j - 1] - 200);//参加或弃权
            }
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1] - 200, dp[i - 1][j] - 200));
            }
            if (a[i] < b[j]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 200;
            }
        }
    }
    cout << dp[n][n];
    return 0;
}