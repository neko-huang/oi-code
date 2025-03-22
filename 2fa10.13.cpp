#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;
int main() {
	char ride[100], team[100]; long long sumr = 1, sumt = 1;
	scanf("%s%s", &ride, &team);
	for (int i = 0; ride[i] != '\0'; i++) {
		sumr *= ride[i] - 'A'+1;
	}
	//printf("%lld\n", sumr);
	for (int i = 0; team[i] != '\0'; i++) {
		sumt *= team[i] - 'A' + 1;
	}
	//printf("%lld\n", sumt);
	if (sumr % 47 == sumt % 47) {
		printf("GO");
	}
	else {
		printf("STAY");
	}
	return 0;
}