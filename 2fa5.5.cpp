#include<stdio.h>
using namespace std;
int main() {
	int sum = 1;
	for (int i = 2; i <= 10; i++) {
		sum += 1; sum *= 2;
	}
	printf("%d", sum);
}