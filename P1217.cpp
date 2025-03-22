#include <stdio.h>
using namespace std;
#pragma warning (disable:4996)
bool hw(int a) {
    int a1[15] = { 0 }, len = 0;
    for (; a != 0; len++) { a1[len] = a % 10; a /= 10; }
    int temp = len / 2 ;
    for (int i = 0; i <= temp; i++) {
        if (a1[temp - i] != a1[temp + i]) { return false; }
    }
    return true;
}
bool zy(int a) {
    //int temp = a / 2+1;
    for (int i = 2; i <= a/i; i++) {
        if (a % i == 0) { return false; }
    }
    return true;
}
int main() {
    //cout << hw(494)<<hw(491);
    int a, b;
    scanf("%d%d",&a,&b);
    for (int i = a; i <= b; i += 2) {
        if (i % 2 == 0) { i++; }
        if (i == 11) { printf("11\n"); }
        if (i >= 12 and i < 100) { i = 99; }
        if (i >= 1000 and i < 10000) {i = 9999;}
        if (i >= 100000 and i < 1000000) {i = 999999; }
        if (i >= 10000000 and i < 100000000) { i = 99999999; }
        if (hw(i) == true) { if (zy(i) == true) { printf("%d\n", i); } }
    }
    return 0;
}