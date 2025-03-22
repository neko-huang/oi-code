#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	char a; scanf("%c", &a);
	for (int i = 1; i <= 2; i++) { printf(" "); }printf("%c\n", a);
	for (int i = 1; i <= 2; i++) { printf(" "); }printf("%c\n", a);
	for (int i = 1; i <= 5; i++) { printf("%c", a); }printf("\n");
	for (int i = 1; i <= 2; i++) { printf(" "); }printf("%c\n", a);
	for (int i = 1; i <= 2; i++) { printf(" "); }printf("%c\n", a);
	return 0;
}