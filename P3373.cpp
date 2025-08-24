//AC 100 
//WA 30 详见提交记录




#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = int(1e5 + 5);
int mod = 0;

struct node {
    int l, r;
    int sum;
    int lzt1, lzt2; // lzt1: 加法标记, lzt2: 乘法标记
};

node tree[maxn << 2];
int a[maxn];

void upd(int x) {
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % mod;
    return;
}

void pushdown(int x) {
    if (tree[x].lzt2 != 1) {
        // 更新左子节点的乘法标记
        tree[x * 2].lzt2 = (1LL * tree[x * 2].lzt2 * tree[x].lzt2) % mod;
        // 更新左子节点的加法标记（乘法标记会影响加法标记）
        tree[x * 2].lzt1 = (1LL * tree[x * 2].lzt1 * tree[x].lzt2) % mod;
        // 更新左子节点的区间和
        tree[x * 2].sum = (1LL * tree[x * 2].sum * tree[x].lzt2) % mod;

        // 同样更新右子节点
        tree[x * 2 + 1].lzt2 = (1LL * tree[x * 2 + 1].lzt2 * tree[x].lzt2) % mod;
        tree[x * 2 + 1].lzt1 = (1LL * tree[x * 2 + 1].lzt1 * tree[x].lzt2) % mod;
        tree[x * 2 + 1].sum = (1LL * tree[x * 2 + 1].sum * tree[x].lzt2) % mod;

        // 重置当前节点的乘法标记
        tree[x].lzt2 = 1;
    }
    if (tree[x].lzt1 != 0) {
        // 更新左子节点的加法标记
        tree[x * 2].lzt1 = (tree[x * 2].lzt1 + tree[x].lzt1) % mod;
        // 更新左子节点的区间和（使用long long防止溢出）
        tree[x * 2].sum = (tree[x * 2].sum + 1LL * (tree[x * 2].r - tree[x * 2].l + 1) * tree[x].lzt1) % mod;

        // 同样更新右子节点
        tree[x * 2 + 1].lzt1 = (tree[x * 2 + 1].lzt1 + tree[x].lzt1) % mod;
        tree[x * 2 + 1].sum = (tree[x * 2 + 1].sum + 1LL * (tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1) * tree[x].lzt1) % mod;

        // 重置当前节点的加法标记
        tree[x].lzt1 = 0;
    }
    return;
}

void build_tree(int x, int bl, int br) {
    tree[x].lzt1 = 0;
    tree[x].lzt2 = 1;
    tree[x].l = bl;
    tree[x].r = br;
    if (bl == br) {
        tree[x].sum = a[bl] % mod;
        return;
    }
    int mid = (bl + br) >> 1;
    build_tree(x * 2, bl, mid);
    build_tree(x * 2 + 1, mid + 1, br);
    upd(x);
    return;
}

void oper1(int x, int al, int ar, int n) {
    if (al <= tree[x].l && tree[x].r <= ar) {
        tree[x].lzt1 = (tree[x].lzt1 + n) % mod;
        tree[x].sum = (tree[x].sum + 1LL * (tree[x].r - tree[x].l + 1) * n) % mod;
        return;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (al <= mid) {
        oper1(x * 2, al, ar, n);
    }
    if (mid < ar) {
        oper1(x * 2 + 1, al, ar, n);
    }
    upd(x);
    return;
}

void oper2(int x, int al, int ar, int n) {
    if (al <= tree[x].l && tree[x].r <= ar) {
        tree[x].lzt2 = (1LL * tree[x].lzt2 * n) % mod;
        tree[x].lzt1 = (1LL * tree[x].lzt1 * n) % mod;
        tree[x].sum = (1LL * tree[x].sum * n) % mod;
        return;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (al <= mid) {
        oper2(x * 2, al, ar, n);
    }
    if (mid < ar) {
        oper2(x * 2 + 1, al, ar, n);
    }
    upd(x);
    return;
}

int query(int x, int ql, int qr) {
    if (ql <= tree[x].l && tree[x].r <= qr) {
        return tree[x].sum;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    long long s = 0; // 使用long long暂存和，防止溢出
    if (ql <= mid) {
        s = (s + query(x * 2, ql, qr)) % mod;
    }
    if (mid < qr) {
        s = (s + query(x * 2 + 1, ql, qr)) % mod;
    }
    return s % mod;
}

int read() {
    int igt = 0, sgn = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            sgn = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        igt = (igt << 3) + (igt << 1) + (c - '0');
        c = getchar();
    }
    return igt * sgn;
}

int main() {
    int n = read(), q = read();
    mod = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        a[i] %= mod;
        if (a[i] < 0) a[i] += mod; // 确保非负
    }
    build_tree(1, 1, n);
    while (q--) {
        int opr = read(), x = read(), y = read();
        if (opr == 1) {
            int k = read() % mod;
            if (k < 0) k += mod; // 确保非负
            oper2(1, x, y, k);
        }
        else if (opr == 2) {
            int k = read() % mod;
            if (k < 0) k += mod; // 确保非负
            oper1(1, x, y, k);
        }
        else if (opr == 3) {
            int ans = query(1, x, y);
            ans %= mod;
            if (ans < 0) ans += mod; // 确保非负
            cout << ans << '\n';
        }
    }
    return 0;
}