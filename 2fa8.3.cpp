#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	char a; scanf("%c", &a);
	if ('A' <= a and a <= 'Z') {
		printf("A"); return 0;
	}
	if ('a' <= a and a<= 'z') {
		printf("a"); return 0;
	}
	if ('0' <= a and a<= '9') {
		printf("0"); return 0;
	}
	return 0;
}