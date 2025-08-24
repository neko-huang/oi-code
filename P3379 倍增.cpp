
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = int(5e5) + 5;

vector<int> G[maxn];
int lg2[maxn];
int depth[maxn], fa[maxn][31];

void dfs(int x, int fx) {
    fa[x][0] = fx;
    depth[x] = depth[fx] + 1;
    for (int i = 0; i < G[x].size(); i++) {
        int tmp = G[x][i];
        if (tmp == fx) continue;
        dfs(tmp, x);
    }
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    while (depth[a] > depth[b]) {
        a = fa[a][lg2[depth[a] - depth[b]]];
    }
    if (a == b) return a;
    for (int i = lg2[depth[a]]; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

int read() {
    int igt = 0, sgn = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') sgn = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        igt = (igt << 3) + (igt << 1) + c - '0';
        c = getchar();
    }
    return igt * sgn;
}

int main() {
    int n = read(), m = read(), s = read();
    for (int i = 2; i <= n; i++) {
        lg2[i] = lg2[i / 2] + 1;
    }

    for (int i = 1; i < n; i++) {
        int x = read(), y = read();
        G[x].push_back(y);
        G[y].push_back(x);
    }

    depth[0] = -1;
    dfs(s, 0);

    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }

    while (m--) {
        int a = read(), b = read();
        cout << LCA(a, b) << '\n';
    }
    return 0;
}
