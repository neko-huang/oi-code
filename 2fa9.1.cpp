#include <stdio.h>
using namespace std;
short c[30] = { 0 };
#pragma warning (disable:4996)
int main() {
    char a;
    do {
        scanf("%c", &a);
        if (a != '%') {
            c[a - 'a' + 1]++;
        }
    } while (a != '%');
    int big ;
    for (int i = 1; i <= 26; i++) {
        big = 1;
        for (int o = 2; o <= 26; o++) {
            if (c[big] < c[o]) {
                big = o;
            }
        }
        if (c[big] == 0) { break; }
        printf("%c %d\n", big - 1 + 'A', c[big] );
        c[big] = 0;
    }
}