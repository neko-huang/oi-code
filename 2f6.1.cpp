#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main(){
	int list[5],sum=0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &list[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\n", list[i]);
		sum += list[i];
	}
	printf("%d",sum);
}