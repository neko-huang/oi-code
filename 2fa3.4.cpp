#include<iostream>
using namespace std;
int main() {
    int n, m; double sum = 0;
    cin >> n;
    int ct = n;
    while (n > 0) {
        cin >> m;
        sum += m;
        n--;
    }
    printf("%.2lf", sum / ct);
}