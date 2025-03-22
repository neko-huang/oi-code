#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n, sum; scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		sum = 1;
		for (int o = 2; o < i / o; o++) {
			if (i % o == 0) {
				sum += o; sum += i / o;
			}
		}
		if (sum == i) { printf("%d\n", i); }
	}
}
