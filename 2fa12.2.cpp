#include<iostream>
using namespace std;
unsigned char bucket[100001]; short a[1000];
int main() {
	int n, tmp; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		bucket[tmp]++;
	}
	int cnt = 0;
	for (int i = 0; i <= 100000; i++) {
		if (bucket[i]) {
			a[cnt++] = i;
		}
	}
	cout << cnt<<'\n';
	for (int i = 0; i < cnt; i++) {
		cout << a[i] << ' ';
	}
}