#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int N, M;
    ll X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(make_pair(v, 1)); 
    }


    vector<vector<pair<int, ll>>> layered_graph(2 * N);

    for (int u = 0; u < N; u++) {
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            ll w = edge.second;
            layered_graph[u].push_back(make_pair(v, w)); 
        }
    }


    for (int u = 0; u < N; u++) {
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            ll w = edge.second;
            layered_graph[v + N].push_back(make_pair(u + N, w)); 
        }
    }


    for (int i = 0; i < N; i++) {
        layered_graph[i].push_back(make_pair(i + N, X));     
        layered_graph[i + N].push_back(make_pair(i, X));    
    }

    vector<ll> dist(2 * N, INF);
    dist[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        pair<ll, int> top = pq.top();
        pq.pop();
        ll d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (const auto& edge : layered_graph[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    ll ans = min(dist[N - 1], dist[2 * N - 1]);
    cout << ans << endl;

    return 0;
}