#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
	int n ;double fbni[100] = { 0 }; double sum = 0;
	scanf("%d",&n);
	fbni[1] = fbni[2] = 1;
	for (int i = 3; i <= n+2 ; i++) {
		fbni[i] = fbni[i - 1] + fbni[i - 2];
	}
	for (int i = 2; i <= n + 1; i++) {
		sum += fbni[i + 1] / fbni[i];
	}
	printf("%.2lf", sum);
}