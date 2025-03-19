#include <iostream>
using namespace std;
const int maxn = int(1e6 + 5);
int que1[maxn];
int que2[maxn];
int a[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    int frt = 1, bck = 0;
    for (int i = 1;i <= n;i++) {

        while (frt <= bck and i - que1[frt] >= m) {
            frt++;
        }
        while (frt <= bck and a[que1[bck]] > a[i]) {
            bck--;
        }
        que1[++bck] = i;
        if (i >= m) {
            printf("%d ", a[que1[frt]]);
        }
    }
    printf("\n");
    frt = 1, bck = 0;
    for (int i = 1;i <= n;i++) {

        while (frt <= bck and i - que2[frt] >= m) {
            frt++;
        }
        while (frt <= bck and a[que2[bck]] < a[i]) {
            bck--;
        }
        que2[++bck] = i;
        if (i >= m) {
            printf("%d ", a[que2[frt]]);
        }
    }
    return 0;
}