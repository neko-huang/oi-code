#include <iostream>
using namespace std;
int main() {
    unsigned long long a, b, c;
    cin >> a >> b;
    if (a == 0 or b == 0) {
        cout << "0";
        return 0;
    }
    a > b ? c = b : c = a;
    unsigned long long d = c / 2 - 1;
    while (d < c) {
        if (a % c == 0 and b % c == 0) {
            cout << c;
            return 0;
        }
        c--;
    }
    cout << '1';
    return 0;
}