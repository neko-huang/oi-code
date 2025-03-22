#include <iostream>
#include <vector>
using namespace std;
struct node {
	int to, qu;
};
int n, m, x; node tp;
int cnt; const int inf = 1e9 + 7;
vector <node> dian[5005]; bool check[5005];
int dis[5005] = {inf};
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> tp.to >> tp.qu;
		dian[x].push_back(tp);
	}
	dis[1] = 0; check[1] = 1; int invis = 1;
	for (int i = 0; i < dian[invis].size(); i++) {
		if (dis[dian[invis][i].to] > dian[invis][i].qu) {
			dis[dian[invis][i].to] = dian[invis][i].qu;
		}
	}
}