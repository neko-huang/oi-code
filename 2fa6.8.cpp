#include <stdio.h>
using namespace std;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int o = 1; o <= i; o++) {
			printf("%d*%d=%d ",o,i,o*i);
		}
		printf("\n");
	}
}