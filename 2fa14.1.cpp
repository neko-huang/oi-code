#include <iostream>
using namespace std;
#pragma warning (disable:4996)
struct milk {
	int cost, liang;
};
void in(int &a) {
	scanf("%d", &a);
	return;
}
void out(int &a) {
	printf("%d", a);
	return;
}
int main() {
	milk farm[5005],tmp;
	int n, m,sum = 0;
	in(n); in(m);
	for (int i = 1; i <= m; i++) {
		in(farm[i].cost);
		in(farm[i].liang);
	}
	bool flag;
	for (int i = 1; i <= m; i++) {
		flag = 0;
		for (int p = 1; p <= m - i; p++) {
			if (farm[p].cost > farm[p + 1].cost) {
				tmp = farm[p]; farm[p] = farm[p+1]; farm[p + 1] = tmp;
				flag = 1;
			}
		}
		if (flag==0) { break; }
	}
	int l=1;
	while (n > 0) {
		while (n > 0 && farm[l].liang > 0) {
			n--;
			farm[l].liang--;
			sum += farm[l].cost;
		}
		l++;
	}
	out(sum);
}