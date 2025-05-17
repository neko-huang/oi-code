#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = int(3e5 + 5);

int a[maxn];
bool high[maxn], low[maxn];
int llow[maxn], rhigh[maxn] = { maxn };
stack <int> inc, dec1;
int main() {
    memset(llow, -1, sizeof(llow));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n < 4) {
        cout << 0;
        return 0;
    }
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
            high[i] = true;
        }
        if (a[i] < a[i - 1] and a[i] < a[i + 1]) {
            low[i] = true;
        }
    }



    for (int i = 1; i <= n; i++) {
        while (!inc.empty() and a[inc.top()] >= a[i]) {
            inc.pop();
        }
        if (!inc.empty()) llow[i] = inc.top();
        inc.push(i);
    }
    for (int i = n; i >= 1; i--) {
        while (!dec1.empty() and a[dec1.top()] <= a[i]) {
            dec1.pop();
        }
        if (!dec1.empty()) rhigh[i] = dec1.top();
        dec1.push(i);
    }
    int res = 0;
    for (int i = 2; i < n - 1; i++) {
        if (high[i]) {
            int left = llow[i];
            int right = rhigh[i];
            if (left != -1 and right != maxn and low[left] and low[right]) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
