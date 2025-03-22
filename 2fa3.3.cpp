#include <iostream>
using namespace std;
int main() {
    int M, N; long long ll = 0;
    cin >> M >> N;
    while (M <= N) {
        if (M % 2 == 1) {
            ll += M;
        }
        M++;
    }
    cout << ll;
    return 0;
}