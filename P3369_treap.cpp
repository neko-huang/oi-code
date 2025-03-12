#include <iostream>
using namespace std;
const int maxn = int(1e5 + 5);
typedef unsigned long long ull;
int val[maxn], pro[maxn];
int siz[maxn];
int son[maxn][2];
int num[maxn];
int rt, cnt;
ull merand() {
	static ull seed;
	return (seed *= 998244353) % 2147483647;
}
void clear(int x) {
	num[x]=val[x] = pro[x] = siz[x] = son[x][0] = son[x][1] = 0;
}
void upd(int x) {
	siz[x] = siz[son[x][0]] + siz[son[x][1]] + 1;
}
int newnode(int x) {
	val[++cnt] = x;
	pro[cnt] = merand();
	siz[cnt] = 1;
	num[cnt] = 1;
	return cnt;
}
void rotate(int &x,int tag) {
	int p = son[x][tag];
	son[x][tag] = son[p][!tag];
	son[p][!tag] = x;
	upd(x);
	upd(p);
	x = p;
}
int main() {

}