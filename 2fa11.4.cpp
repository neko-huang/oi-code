#include<iostream>
using namespace std;
unsigned char bucket[1000000];
int main() {
	int n,tmp; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		bucket[tmp]++;
	}
	int max=0;
	for (int i = 1; i <= 1000000; i++) {
		if (bucket[max] < bucket[i]) {
			max = i;
		}
	}
	cout << max <<'\n'<< int(bucket[max]);
}