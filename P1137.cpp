#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100005;  // 根据题目要求设置足够大的值

vector<int> G[maxn];
int topo[maxn];
int cnt;
int dp[maxn];
int in_degree[maxn];  // 新增入度数组

int read() {
    int igt = 0, sgn = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') sgn = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        igt = igt * 10 + (c - '0');
        c = getchar();
    }
    return igt * sgn;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        G[u].push_back(v);
        in_degree[v]++;  // 统计入度
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);  // 所有入度为0的节点入队
        }
    }

    cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo[++cnt] = u;  // 记录拓扑序
        for (int v : G[u]) {
            if (--in_degree[v] == 0) {  // 减少后继节点的入度
                q.push(v);
            }
        }
    }

    // 初始化dp数组
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    // 按拓扑序处理每个节点
    for (int i = 1; i <= cnt; i++) {
        int u = topo[i];
        for (int v : G[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dp[i]);
    }

    return 0;
}