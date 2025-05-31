#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

vector<int> computeL(const vector<int>& A) {
    int n = A.size();
    vector<int> L(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && A[stk.top()] < A[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            L[i] = stk.top();
        }
        stk.push(i);
    }
    return L;
}

vector<int> computeR(const vector<int>& A) {
    int n = A.size();
    vector<int> R(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            R[i] = stk.top();
        }
        stk.push(i);
    }
    return R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    auto L = computeL(A);
    auto R = computeR(A);

    vector<ll> diff1(N + 2, 0);
    vector<ll> diff2(N + 2, 0);

    for (int i = 0; i < N; ++i) {
        int a = i - L[i];
        int b = R[i] - i;

        if (a >= b) {
            int k1 = b;
            if (k1 >= 1) {
                int l = 1, r = k1;
                diff2[l] += A[i];
                if (r + 1 <= N) {
                    diff2[r + 1] -= A[i];
                }
            }

            int l2 = b + 1, r2 = a;
            if (l2 <= r2) {
                ll val = (ll)A[i] * b;
                diff1[l2] += val;
                if (r2 + 1 <= N) {
                    diff1[r2 + 1] -= val;
                }
            }

            int l3 = a + 1, r3 = a + b - 1;
            if (l3 <= r3 && r3 <= N) {
                ll coeff = A[i];
                ll const_term = (ll)(a + b) * coeff;
                diff1[l3] += const_term;
                if (r3 + 1 <= N) {
                    diff1[r3 + 1] -= const_term;
                }

                diff2[l3] -= coeff;
                if (r3 + 1 <= N) {
                    diff2[r3 + 1] += coeff;
                }
            }
        }
        else {
            int k1 = a;
            if (k1 >= 1) {
                int l = 1, r = k1;
                diff2[l] += A[i];
                if (r + 1 <= N) {
                    diff2[r + 1] -= A[i];
                }
            }

            int l2 = a + 1, r2 = b;
            if (l2 <= r2) {
                ll val = (ll)A[i] * a;
                diff1[l2] += val;
                if (r2 + 1 <= N) {
                    diff1[r2 + 1] -= val;
                }
            }

            int l3 = b + 1, r3 = a + b - 1;
            if (l3 <= r3 && r3 <= N) {
                ll coeff = A[i];
                ll const_term = (ll)(a + b) * coeff;
                diff1[l3] += const_term;
                if (r3 + 1 <= N) {
                    diff1[r3 + 1] -= const_term;
                }

                diff2[l3] -= coeff;
                if (r3 + 1 <= N) {
                    diff2[r3 + 1] += coeff;
                }
            }
        }
    }

    vector<ll> sum(N + 1, 0);
    ll ndiff1 = 0;
    ll ndiff2 = 0;
    for (int k = 1; k <= N; ++k) {
        ndiff1 += diff1[k];
        ndiff2 += diff2[k];
        sum[k] = ndiff1 + ndiff2 * k;
    }

    for (int k = 1; k <= N; ++k) {
        cout << sum[k] << '\n';
    }

    return 0;
}