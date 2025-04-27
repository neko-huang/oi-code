#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll base = 2; 
    while (base <= n) {
        ll smaxb = n / base;
        if (smaxb < 1) {
            base *= 2;
            continue;
        }
        ll maxb = (ll)sqrt(smaxb);

        while (maxb * maxb > smaxb) {
            maxb--;
        }
        while ((maxb + 1) * (maxb + 1) <= smaxb) {
            maxb++;
        }   

        if (maxb >= 1) {
            ans += (maxb + 1) / 2;
        }
        if (2* base > n) {
            break;
        }
        base *= 2;
    }
    cout << ans;
    return 0;
}