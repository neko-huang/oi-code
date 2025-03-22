#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int list[100005];
void qsort(int a[], int h, int t) {
	int q = h,p=t,m=a[(h+t)/2],temp;
	while (q <= p){
		while (a[q] < m) { q++; }
		while (a[p] > m) { p--; }
		if (q <= p) {
			temp = a[q]; a[q] = a[p]; a[p] = temp;
			q++; p--;
		}
	} 
	if (h < p) { qsort(list, h, p); }
	if (q < t) { qsort(list, q, t); }
}
int main() {
	int n; scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	qsort(list, 1, n);
	for (int o = 1; o <= n; o++) {
		printf("%d ", list[o]);
	}
	return 0;
}