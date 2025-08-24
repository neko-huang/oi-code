#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    string s = to_string(x);
    int len = s.size();

    if (len == n) {
        cout << 0 << endl;
        return 0;
    }
    if (len > n) {
        cout << -1 << endl;
        return 0;
    }
    if (x == 1) {
        cout << -1 << endl;
        return 0;
    }

    queue<pair<long long, int>> q;
    unordered_set<long long> visited;

    q.push({ x, 0 });
    visited.insert(x);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        long long num = current.first;
        int steps = current.second;

        string num_str = to_string(num);
        int current_len = num_str.size();

        if (current_len == n) {
            cout << steps << endl;
            return 0;
        }

        if (current_len > n) {
            continue;
        }

        for (char c : num_str) {
            int y = c - '0';
            if (y == 0 || y == 1) {
                continue;
            }

            long long new_num = num * y;
            if (visited.find(new_num) != visited.end()) {
                continue;
            }

            string new_num_str = to_string(new_num);
            int new_len = new_num_str.size();

            if (new_len == n) {
                cout << steps + 1 << endl;
                return 0;
            }
            if (new_len < n) {
                visited.insert(new_num);
                q.push({ new_num, steps + 1 });
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
