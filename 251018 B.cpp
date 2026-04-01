#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    map<string, int> cnt;

    for (int i = 0; i <= N - K; i++) {
        string sub = S.substr(i, K);
        cnt[sub]++;
    }


    int max = 0;
    for (map<string, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second > max) {
            max = it->second;
        }
    }

    vector<string> result;
    for (map<string, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second == max) {
            result.push_back(it->first);
        }
    }

    sort(result.begin(), result.end());

    cout << max << endl;
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}