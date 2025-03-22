#include <iostream>
using namespace std;
int main() {
    int n, k, sum = 0, temp;
    cin >> n >> k;
    sum = n;
    while (n >= k) {
        temp = n / k;
        n %= k;
        sum += temp;
        n += temp;
    }
    cout << sum;
    return 0;
}