
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 3e6 + 5;
int trie[MAXN][62], num[MAXN], cnt;

int getnum(char x) {
    if (x >= '0' && x <= '9') return x - '0';
    if (x >= 'a' && x <= 'z') return x - 'a' + 10;
    if (x >= 'A' && x <= 'Z') return x - 'A' + 36;
    return -1;
}

void insert(const string& s) {
    int now = 0;
    for (char c : s) {
        int idx = getnum(c);
        if (!trie[now][idx]) trie[now][idx] = ++cnt;
        now = trie[now][idx];
        num[now]++;
    }
}

int query(const string& s) {
    int now = 0, res = 0;
    for (char c : s) {
        int idx = getnum(c);
        if (!trie[now][idx]) return res;
        now = trie[now][idx];

    }
    return num[now];
}

void clear() {
    for (int i = 0; i <= cnt; i++) {
        memset(trie[i], 0, sizeof(trie[i]));
        num[i] = 0;
    }
    cnt = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        clear();
        int n, q; cin >> n >> q;
        string s;
        while (n--) { cin >> s; insert(s); }
        while (q--) { cin >> s; cout << query(s) << '\n'; }
    }
    return 0;
}
