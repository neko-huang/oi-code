#include <iostream>
using namespace std;

const int MOD = 998244353;

// 快速幂
long long pow_mod(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 模逆元
long long inv(long long a, long long mod) {
    return pow_mod(a, mod - 2, mod);
}

// 计算多重组合数 C(n, a, b, c) = n! / (a! * b! * c!)
long long multi_comb(int n, int a, int b, int c) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = res * i % MOD;
    }
    for (int i = 1; i <= a; ++i) {
        res = res * inv(i, MOD) % MOD;
    }
    for (int i = 1; i <= b; ++i) {
        res = res * inv(i, MOD) % MOD;
    }
    for (int i = 1; i <= c; ++i) {
        res = res * inv(i, MOD) % MOD;
    }
    return res;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    // 答案是 C(A+B+C, A, B, C)
    cout << multi_comb(A + B + C, A, B, C) << endl;
    return 0;
}
