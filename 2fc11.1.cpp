#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	long long n, a[100], tmp; bool flag=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		//scanf("%lld", &a[i]);
		cin>>a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int o = 1; o <= n-i; o++) {
			if (a[o] > a[o + 1]) {
				tmp = a[o];
				a[o] = a[o + 1];
				a[o + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) { break; }
		flag = 0;
	}
	for (int i = n; i >= 1; i--) {
		//printf("%lld\n",a[i]);
		cout<<a[i]<<'\n';
	}
}