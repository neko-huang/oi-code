#include <stdio.h>
#include <cmath>
using namespace std;
bool check[45]; double dist[45][45];
struct cheese {
	double x, y;
};
cheese ch[45],yuan;
double operator*(cheese a,cheese b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double min = 1e99,dis=0; int n;
void dfs(int q,cheese tmp,int c) {//他在吃第几块cheese
	if (q > n) { 
		if (dis < min)
			min = dis;
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			if (dist[c][i]) {
				dis += dist[c][i];
			}
			else {
				dis += dist[c][i] = tmp * ch[i];
			}
			check[i] = 1;
			dfs(q + 1, ch[i],i);
			dis -= dist[c][i];
			check[i] = 0;
		}
	}
}
#pragma warning (disable:4996)
int main() {
	ch[0].x = 0; ch[0].y = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &ch[i].x, &ch[i].y); 
	}
	dfs(1,ch[0], 0);
	printf("%.2lf", min);
}