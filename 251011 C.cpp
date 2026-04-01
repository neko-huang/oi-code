#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    int ans = M; 

    for (int mask = 0; mask < (1 << N); mask++) {
        int tmp = 0; 

        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;

            bool uColor = (mask >> u) & 1; 
            bool vColor = (mask >> v) & 1; 

            if (uColor == vColor) {
                tmp++; 
            }
        }

        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}