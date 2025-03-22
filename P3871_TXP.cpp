#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
vector<int> v;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int main() {
    int n, m;
    n=read();
    for (size_t i = 0; i < n; i++) {
        v.push_back(read());
    }
    sort(v.begin(), v.end());
    m=read();
    while (m--) {
        string s;
        cin >> s;
        if (s == "mid") {
            if (v.size() % 2) {
                printf("%lld\n", v[(int(v.size() / 2))]);
            }
            else {
                printf("%lld\n", min(v[v.size() / 2 - 1], v[v.size() / 2]));
            }
        }
        else {
            int x = read();
            v.insert(lower_bound(v.begin(), v.end(), x), x);
        }
    }

    return 0;
}
