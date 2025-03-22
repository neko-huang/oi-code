#include <iostream>
using namespace std;
int main() {
    short a, b, m = 1000;
    while (m <= 9999) {
        a = m / 100;
        b = m % 100;
        if ((a + b) * (a + b) == m) {
            printf("%d\n", m);
        }
        m++;
    }
    return 0;
}