#include<iostream>
using namespace std;
unsigned char bucket[100001];
int main() {
	int n, tmp; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		bucket[tmp]++;
	}
	for (int i = 100000; i >= 0; i--) {
		for (int o = 1; o <= bucket[i]; o++) {
			cout << i << ' ';
		}
	}
}