#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int a[500005], b[500005]; long long cnt;
void jipai(int h,int t) {
	if (h + 1 == t)return;
	int middle = (h + t) / 2;
	jipai(h, middle);
	jipai(middle, t);
	int tl = h, tr = middle, up = h;
	while (tl < middle and tr < t) {
		if (a[tl] <= a[tr]) {
			b[up++] = a[tl++];
		}
		else {
			b[up++] = a[tr++]; cnt += middle - tl ;
		}
	}
	while (tl < middle)
		b[up++] = a[tl++];
	while (tr < t)
		b[up++] = a[tr++];
	for (int i = h; i < t; i++) {
		a[i] = b[i];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	jipai(1, n+1);
	printf("%lld", cnt);
}