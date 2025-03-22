#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main(){
	long long  n; scanf("%lld",&n); 
	do {
		if (n % 2 == 0) {
			n /= 2; 
		}
		else{
			n = n * 3 + 1; 
		}
		printf("%lld\n", n);
	} while (n != 1);
	return 0;
}