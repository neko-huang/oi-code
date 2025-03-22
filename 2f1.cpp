#include <iostream>
using namespace std;
int main() {
	double cnt=0, tmp;
	int n; cin >> n;
	for (int i = 1; i <= n; i++,cnt+=tmp) {
		cin >> tmp;
	}
	printf("%.2lf", cnt);
}