#include <iostream>
#include <string.h>
using namespace std;
int cnt[2][int(1e6 + 5)];
int now[2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    cin >> m;
    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == '0') {
            cnt[0][++now[0]] = i;
        }
        if (tmp[i] == '1') {
            cnt[1][++now[1]] = i;
        }
    }
    while (m--) {
        int a, k;
        cin >> a >> k;
        if (k > now[a]) {
            cout << "-1\n";
        }
        else {
            cout << cnt[a][k] << '\n';
        }
    }
    return 0;
}