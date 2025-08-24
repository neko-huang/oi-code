#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 1e3 + 5;

int read() {
    int num = 0, sgn = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            sgn = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c - '0');
        c = getchar();
    }
    return num * sgn;
}

vector<int> G[maxn];
int rec[maxn];
int cnt;
vector<int> ans;
bool vis[maxn];

void dfs(int x, int y) {
    if (x == y) {
        int len = min(cnt, int(ans.size()));
        for (int i = 0; i < len; i++) {
            if (ans[i] > rec[i]) {
                ans.clear();
                ans.resize(cnt);
                for (int j = 0; j < cnt; j++) {
                    ans[j]=rec[j];
                }
                return;
            }
            else if (ans[i] == rec[i]) {
                continue;
            }
            else {
                return;
            }
        }
        if (len == cnt) {
            ans.clear();
            ans.resize(len);
            for (int i = 0; i < len; i++) {
                ans[i] = rec[i];
            }
        }
        return;
    }

    for (int i = 0; i < G[x].size(); i++) {
        if (!vis[G[x][i]]) {
            vis[G[x][i]] = true;
            rec[cnt++] = G[x][i];
            dfs(G[x][i], y);
            vis[G[x][i]] = false;
            cnt--;
        }
    }
    return;
}

int main() {
    int T = read();
    while (T--) {
        memset(vis, 0, sizeof(vis));
        memset(rec, 0, sizeof(rec));
        int n = read(), m = read(), x = read(), y = read();

        // Çå¿ÕÍ¼
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u = read(), v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }

        cnt = 0;
        ans.clear();
        ans.assign(maxn, 0x3f3f3f3f);
        vis[x]=1;
        rec[cnt++] = x;
        dfs(x, y);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
