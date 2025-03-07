#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = int(1e5 + 5);
struct node {
    int l, r;
    int cnt;
};
node tree[4 * maxn];
void upd(int x) {
    tree[x].cnt = tree[x * 2].cnt + tree[x * 2 + 1].cnt;
}
void build_tree(int x, int bl, int br) {
    tree[x].l = bl;
    tree[x].r = br;
    tree[x].cnt = 0;
    if (bl == br) {
        return;
    }
    int mid = (bl + br) / 2;
    build_tree(x * 2, bl, mid);
    build_tree(x * 2 + 1, mid + 1, br);
    return;
}
struct que {
    int opt, x;
};
vector <int> setm;
vector <int> lite;
vector <que> solve;//:D
void insert(int x, int n) {
    if (tree[x].l == tree[x].r) {
        tree[x].cnt++;
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (n <= mid) {
        insert(x * 2, n);
    }
    else {
        insert(x * 2 + 1, n);
    }
    upd(x);
    return;
}
void delset(int x, int n) {
    if (tree[x].l == tree[x].r) {
        tree[x].cnt--;
        if (tree[x].cnt < 0) {
            tree[x].cnt = 0;
        }
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (n <= mid) {
        delset(x * 2, n);
    }
    else {
        delset(x * 2 + 1, n);
    }
    upd(x);
    return;
}
int query_rank(int x, int n) {
    if (tree[x].l == tree[x].r) {
        return lite[tree[x].l];
    }
    if (tree[x * 2].cnt >= n) {
        return query_rank(x * 2, n);
    }
    else {
        return query_rank(x * 2 + 1, n - tree[x * 2].cnt);
    }
}
int query_modi(int x, int ml, int mr) {
    if (ml <= tree[x].l and tree[x].r <= mr) {
        return tree[x].cnt;
    }
    int ans = 0;
    int mid = (tree[x].l + tree[x].r) / 2;
    if (ml <= mid) {
        ans += query_modi(x * 2, ml, mr);
    }
    if (mr > mid) {
        ans += query_modi(x * 2 + 1, ml, mr);
    }
    return ans;
}
int frt(int x, int n) {
    if (tree[x].l >= n) {
        return -1;
    }
    if (tree[x].l == tree[x].r) {
        return lite[tree[x].l];
    }
    int ans = -1;
    if (tree[x * 2 + 1].cnt) {
        ans = frt(x * 2 + 1, n);
    }
    if (ans == -1 and tree[x * 2].cnt) {
        ans = frt(x * 2, n);
    }
    return ans;
}
int bck(int x, int n) {
    if (tree[x].r <= n) {
        return -1;
    }
    if (tree[x].l == tree[x].r) {
        return lite[tree[x].l];
    }
    int ans = -1;
    if (tree[x * 2].cnt) {
        ans = bck(x * 2, n);
    }
    if (ans == -1 and tree[x * 2 + 1].cnt) {
        ans = bck(x * 2 + 1, n);
    }
    return ans;
}
int read() {
    int n;
    scanf("%d", &n);
    return n;
}
void out(int n, char a) {
    printf("%d%c", n, a);
    return;
}
int main() {
    setm.push_back(0);
    lite.push_back(0);
    int n = read();
    while (n--) {
        solve.push_back(que{ read(),read() });
        if (solve[solve.size() - 1].opt != 4) {
            setm.push_back(solve[solve.size() - 1].x);
            lite.push_back(solve[solve.size() - 1].x);
        }
        else {
            setm.push_back(0);
        }
    }
    sort(lite.begin() + 1, lite.end());
    lite.erase(unique(lite.begin(), lite.end()), lite.end());
    for (int i = 1; i < setm.size(); i++) {
        setm[i] = lower_bound(lite.begin(), lite.end(), setm[i]) - lite.begin();
    }
    build_tree(1, 1, lite.size());
    for (int i = 1; i <= solve.size(); i++) {
        switch (solve[i - 1].opt) {
        case 1:
            insert(1, setm[i]);
            break;
        case 2:
            delset(1, setm[i]);
            break;
        case 3:
            out(query_modi(1, 1, setm[i] - 1) + 1, '\n');
            break;
        case 4:
            out(query_rank(1, solve[i - 1].x), '\n');
            break;
        case 5:
            out(frt(1, setm[i]), '\n');
            break;
        case 6:
            out(bck(1, setm[i]), '\n');
            break;
        }
    }
    return 0;
}