#include <iostream>
using namespace std;
struct node {
    int l, r;
    int lsum, rsum;
    int sum;
    int lzt;
};
const int maxn = int(5 * 1e4 + 5);
node tree[maxn << 3];
int max(int a, int b, int c) {
    return max(a, max(b, c));
}
void build(int x, int bl, int br) {
    tree[x].l = bl;
    tree[x].r = br;
    tree[x].lsum = tree[x].rsum = tree[x].sum = br - bl + 1;
    tree[x].lzt = 0;
    if (bl == br) {
        return;
    }
    int mid = (bl + br) / 2;
    build(x * 2, bl, mid);
    build(x * 2 + 1, mid + 1, br);
    return;
}
void push_down(int x) {
    if (tree[x].lzt) {
        if (tree[x].lzt == 1) {
            tree[x * 2].lzt = 1;
            tree[x * 2 + 1].lzt = 1;
            tree[x * 2].lsum = tree[x * 2].rsum = tree[x * 2].sum = 0;
            tree[x * 2 + 1].lsum = tree[x * 2 + 1].rsum = tree[x * 2 + 1].sum = 0;
        }
        if (tree[x].lzt == 2) {
            tree[x * 2].lzt = 2;
            tree[x * 2 + 1].lzt = 2;
            tree[x * 2].lsum = tree[x * 2].rsum = tree[x * 2].sum = tree[x * 2].r - tree[x * 2].l + 1;
            tree[x * 2 + 1].lsum = tree[x * 2 + 1].rsum = tree[x * 2 + 1].sum = tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1;
        }
        tree[x].lzt = 0;
    }
    return;
}
void upd(int x) {
    if (tree[x * 2].sum == tree[x * 2].r - tree[x * 2].l + 1) {
        tree[x].lsum = tree[x * 2].r - tree[x * 2].l + 1 + tree[x * 2 + 1].lsum;
    }
    else {
        tree[x].lsum = tree[x * 2].lsum;
    }
    if (tree[x * 2 + 1].sum == tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1) {
        tree[x].rsum = tree[x * 2 + 1].r - tree[x * 2 + 1].l + 1 + tree[x * 2].rsum;
    }
    else {
        tree[x].rsum = tree[x * 2 + 1].rsum;
    }
    tree[x].sum = max(tree[x * 2].sum, tree[x * 2 + 1].sum, tree[x * 2].rsum + tree[x * 2 + 1].lsum);
    return;
}
void modify(int x, int live, int ml, int mr) {
    push_down(x);
    if (ml <= tree[x].l and tree[x].r <= mr) {
        if (live == 1) {
            tree[x].sum = tree[x].lsum = tree[x].rsum = 0;
        }
        else {
            tree[x].sum = tree[x].lsum = tree[x].rsum = tree[x].r - tree[x].l + 1;
        }
        tree[x].lzt = live;
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (ml <= mid) {
        modify(x * 2, live, ml, mr);
    }
    if (mr > mid) {
        modify(x * 2 + 1, live, ml, mr);
    }
    upd(x);
    return;
}
int query(int x, int n) {
    push_down(x);
    if (tree[x].l == tree[x].r) {
        return tree[x].l;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (tree[x * 2].sum >= n) {
        return query(x * 2, n);
    }
    else if (tree[x * 2].rsum + tree[x * 2 + 1].lsum >= n) {
        return mid - tree[x * 2].rsum + 1;
    }
    else {
        return query(x * 2 + 1, n);
    }
}
int read() {
    int p;
    scanf("%d", &p);
    return p;
}
int main() {
    int n = read(), m = read();
    build(1, 1, n);
    int opt, x, y;
    while (m--) {
        opt = read();
        if (opt == 1) {
            x = read();
            if (tree[1].sum >= x) {
                int tmp = query(1, x);
                printf("%d\n", tmp);
                modify(1, opt, tmp, tmp + x - 1);
            }
            else {
                printf("0\n");
            }
        }
        else {
            x = read(), y = read();
            modify(1, opt, x, x + y - 1);
        }
    }
    return 0;
}