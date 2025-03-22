#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
struct gold {
	db value, weigth;
};
bool cmp(gold a, gold b) {
	//a.value/a.weigth
	return a.value * b.weigth > b.value * a.weigth;
}
gold a[10005]; db ans = 0;
int main() {
	int N;db M;
	cin >> N>>M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i].weigth >>a[i].value ;
	}
	sort(a + 1, a + N + 1,cmp);
	for (int i = 1; 1; i++) {
		if (a[i].weigth <= M) {
			M -= a[i].weigth;
			ans += a[i].value;
		}
		else {
			ans += a[i].value * M / a[i].weigth;
			break;
		}
	}
	printf("%.2lf", ans);;
}