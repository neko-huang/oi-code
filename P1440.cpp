#include <iostream>
using namespace std;
const int maxn = int(2e6);
int que[maxn + 5];
int lis[maxn + 5];
int frt = 1, bck = 0;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &lis[i]);
    }
    /*
    ji lu xia biao
    min             max
        frt       bck
        frt          bck++
           frt++     bck
    */

    for (int i = 1;i <= n;i++) {
        printf("%d", lis[que[frt]]);
        while (i - que[frt] >= m and frt <= bck) {
            frt++;
        }
        while (lis[i] < lis[que[bck]] and frt <= bck) {
            bck--;
        }
        que[++bck] = i;
    }
    return 0;
}