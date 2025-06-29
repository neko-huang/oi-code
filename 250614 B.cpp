#include <iostream>

using namespace std;
const int maxn = int(1e2 + 5);

int boxes[maxn];
int result[maxn];
int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < Q; ++i) {
        int x;
        cin >> x;
        if (x >= 1) {
            boxes[x]++;
            result[i] = x;
        }
        else {
            int min_balls = boxes[1];
            int min_box = 1;

            for (int j = 2; j <= N; ++j) {
                if (boxes[j] < min_balls) {
                    min_balls = boxes[j];
                    min_box = j;
                }
            }

            boxes[min_box]++;
            result[i] = min_box;
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
