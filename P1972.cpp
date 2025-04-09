#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = int(1e6 + 5);
struct node {
	int lson, rson;
	int vis;
};
node tree[maxn << 5];
vector <int> a;
vector <int> lite;
int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' or c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt * sgn;
}
int cnt;
int ver[maxn];
int build(int bl,int br) {
	int nver = ++cnt;
	if (bl == br) {
		return nver;
	}
	int mid = (bl + br) / 2;
	tree[nver].lson = build(bl, mid);
	tree[nver].rson = build(mid + 1, br);
	return nver;
}
void ins(int cver,int &nver,int x,int il,int ir,int n){
	if (!nver) {
		nver = ++cnt;
	}
	if (il == ir) {
		tree[nver].vis++;
	}
}
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) {
		a.push_back(read());
	}
	lite = a;
	sort(lite.begin(), lite.end());
	int sl = unique(lite.begin(), lite.end())-lite.begin();
	lite.resize(sl);

}