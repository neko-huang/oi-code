#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = int(1e5 + 5);
const int maxk = int(2e5 + 5);
int n, k;
int f[maxn];
struct ele {
	int a, b, c;
	int num=1;//shi ling wo
	int id;//my place
	inline bool operator !=(const ele& other) {
		if (a != other.a) {
			return true;
		}
		if (b != other.b) {
			return true;
		}
		if (c != other.c) {
			return true;
		}
		return false;
	}
}lis[maxn],tt[maxn];
bool cmp1(ele a, ele b) {
	if (a.a != b.a) {
		return a.a < b.a;
	}
	else if (a.b != b.b) {
		return a.b < b.b;
	}
	else {
		return a.c < b.c;
	}
}
int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int tree[maxk];
int ans[maxn];
int lowbit(int x) {
	return x & (-x);
}
int query(int n) {
	int ans = 0;
	for (int i = n; i; i -= lowbit(i)) {
		ans += tree[i];
	}
	return ans;
}
void add(int n, int x) {
	for (int i = n; i <= k; i += lowbit(i)) {
		tree[i] += x;
	}
}
void CDQ(int l, int r) {
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	CDQ(l, mid);
	CDQ(mid + 1, r);
	int frt = l, bck = mid + 1;
	for (; bck <= r; bck++) {
		while (frt <= mid and lis[frt].b<=lis[bck].b) {
			add(lis[frt].c,lis[frt].id);
			frt++;
		}
		f[lis[bck].id] += query(lis[bck].c);
	}
	for (int i = l; i < frt; i++) {
		add(lis[i].c, -lis[i].num);
	}
	frt = l, bck = mid + 1; int t = l;
	while (frt <= mid and bck <= r) {
		if (lis[frt].b <= lis[bck].b) {
			tt[t] = lis[frt++];
		}
		else{
			tt[t] = lis[bck++];
		}
		t++;
	}
	while (frt <= mid) {
		tt[t++] = lis[frt++];
	}
	while (bck <= r) {
		tt[t++] = lis[bck++];
	}
	for (int i = l; i <= r; i++) {
		lis[i] = tt[i];
	}
	return;
}
int main() {
	n=read(), k=read();
	for (int i = 1; i <= n; i++) {
		lis[i].a = read();
		lis[i].b = read();
		lis[i].c = read();
	}
	sort(lis + 1, lis + n + 1, cmp1);
	//A sort already!
	//I have already finished this sort
	int t = 1;
	for (int i = 2; i <= n; i++) {
		if (lis[i] != lis[i - 1]) {
			lis[++t] = lis[i];
		}
		else {
			lis[t].num++;
		}
	}
	int pren = n;
	n = t;
	for (int i = 1; i <= n; i++) {
		lis[i].id = i;
	}
	CDQ(1, n);
	for (int i = 1; i <= n; i++) {
		ans[f[lis[i].id] + lis[i].num - 1] += lis[i].num;
	}
	for (int i = 0; i < pren; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}