#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;

    stack<pair<int, int>> Sstack; 
    int total = 0;    
    int frt = 0; 

    vector<string> results;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            char c;
            cin >> c;

            Sstack.push({ total, frt });

            if (c == '(') {
                total += 1;
            }
            else {
                total -= 1;
            }
            frt = min(frt, total);

        }
        else { 
            pair <int,int> frontstate = Sstack.top();
            Sstack.pop();
            total = frontstate.first;
            frt = frontstate.second;
        }

        if (total == 0 && frt >= 0) {
            results.push_back("Yes");
        }
        else {
            results.push_back("No");
        }
    }

    for (int i = 0; i < results.size();i++) {
        cout << results[i] << "\n";
    }

    return 0;
}