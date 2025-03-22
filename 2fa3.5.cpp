#include <iostream>
using namespace std;
int main() {
    unsigned long long a, b, c;
    cin >> a >> b;
    c = a;
    while (c > 0) {
        if (a % c == 0 and b % c == 0) {
            printf("%llu", c);
            return 0;
        }
        c--;
    }
    return 0;
}