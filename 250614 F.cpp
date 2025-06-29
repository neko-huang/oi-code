
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];

    // 预处理行前缀和
    vector<vector<int>> prefix(H + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            int val = (grid[i - 1][j - 1] == '#') ? 1 : -1;
            prefix[i][j] = prefix[i][j - 1] + val;
        }
    }

    int ans = 0;
    // 枚举左右列
    for (int l = 1; l <= W; ++l) {
        for (int r = l; r <= W; ++r) {
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            int sum = 0;
            // 从上到下计算列区间和
            for (int i = 1; i <= H; ++i) {
                sum += prefix[i][r] - prefix[i][l - 1];
                ans += cnt[sum];
                cnt[sum]++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
    return 0;
}
