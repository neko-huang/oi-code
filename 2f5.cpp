#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int main() {
    int n, A1, T1, tpA=0, tpT=0; char tmp;
    cin >> n; scanf("%c", &tmp);
    for (int i = 1; i <= n; i++) {
        A1 = 0; T1 = 0; scanf("%c", &tmp);
        while (tmp != '\n') {
            if (tmp != 'A') {
                if (tpA > A1)A1 = tpA;
                tpA = 0;
            }
            if (tmp != 'T') {
                if (tpT > T1)T1 = tpT;
                tpT = 0;
            }
            if (tmp == 'A') { tpA++; }
            if (tmp == 'T') { tpT++; }
            scanf("%c", &tmp);
        }
        if (tpT > T1)T1 = tpT;
        tpT = 0;
        if (tpA > A1)A1 = tpA;
        tpA = 0;
        if (A1 >= 13 or T1 >= 13) {
            cout << "Yes" << endl;  
        }
        else {
            cout << "No" << endl;
        }
    }

}