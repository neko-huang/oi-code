
#include "iostream"
#include "vector"
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e5 + 5;

int inv[MAXN];

void precompute_inv() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = ((MOD - 1LL * (MOD / i) )* inv[MOD % i] % MOD) % MOD;
    }
}

void solve() {
    int N, P;
    cin >> N >> P;

    precompute_inv();

    vector<long long> E(N + 2, 0);
    vector<long long> sum(N + 2, 0);
    E[1] = 1;
    sum[1] = 1;
    long long p = 1LL * P * inv[100] % MOD;
    long long q = (1 - p + MOD) % MOD;

    for (int m = 2; m <= N; ++m) {
        // Operation 1: add m with probability p
        long long op1 = p;

        // Operation 2: only when sum[m-1] > 0
        if (sum[m - 1] > 0) {
            long long inv_sum = inv[sum[m - 1]];
            for (int k = 1; k < m; ++k) {
                long long prob = q * E[k] % MOD * inv_sum % MOD;
                E[k] = (E[k] + prob) % MOD;
            }
        }

        E[m] = op1;
        sum[m] = (sum[m - 1] + op1) % MOD;
    }

    for (int k = 1; k <= N; ++k) {
        cout << E[k] << " \n"[k == N];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
