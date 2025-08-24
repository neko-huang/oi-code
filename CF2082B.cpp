#include <iostream>
using namespace std;

int read() {
    int igt = 0, sgn = 1;
    char c = getchar();
    while (c > '9' or c < '0') {
        if (c == '-') {
            sgn = -1;
        }
        c = getchar();
    }
    while (c >= '0' and c <= '9') {
        igt = (igt << 3) + (igt << 1) + c - '0';
        c = getchar();
    }
    return igt * sgn;
}
int main() {
    int t = read();
    while (t--) {
        int x = read(), n = read(), m = read();
        int ans1 = x, ans2 = x;
        for (int i = 1; i <= m; i++) {
            ans1 = (ans1 + 1) / 2;
            if (ans1 == 1 or ans1 == 0) {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            ans1 /= 2;
            if (ans1 == 0) {
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            ans2 /= 2;
            if (ans2 == 0) {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            ans2 = (ans2 + 1) / 2;
            if (ans2 == 0 or ans2 == 1) {
                break;
            }
        }
        cout << ans1 << ' ' << ans2 << '\n';
    }
    return 0;
}