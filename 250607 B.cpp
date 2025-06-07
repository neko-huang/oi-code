#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxX(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n + 2, 0); 
    for (int num : nums) {
        count[min(num, n)]++;
    }
    for (int i = n; i >= 1; i--) {
        count[i] += count[i + 1];
        if (count[i] >= i) {
            return i;
        }
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << findMaxX(A) << endl;
    return 0;
}
