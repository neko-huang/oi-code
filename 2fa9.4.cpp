#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
int main() {
	char a; int b; float c; double d;
	scanf("%c%d%f%lf", &a, &b, &c, &d);
	printf("%c %d %.6f %.6lf", a, b, c, d);
	return 0;
}