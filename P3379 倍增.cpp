#include <iostream>
using namespace std;
const int maxn = int(5e5 + 5);

struct node {
	int u, v;
	int nxt,fa=0;
};

int cnt;
node tree[maxn];

void addedge(int u, int v) {
	tree[++cnt].u = u;
	tree[cnt].v = v;
	tree[cnt].nxt = tree[cnt].fa;
	tree[cnt]
}

int main() {

}