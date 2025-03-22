#include <iostream>
using namespace std;
int main() {
    int score;
    while (cin >> score) {
        if (score > 100 or score < 0) {
            cout<<"Score is error!";
        }
        else {
            if (score > 89) {
                cout<<"A";
            }
            else if (score > 79) {
                cout<<"B";
            }
            else if (score > 69) {
                cout<<"C";
            }
            else if (score > 59) {
                cout<<"D";
            }
            else {
                cout<<"E";
            }
        }
        cout << '\n';
    }
    return 0;
}
int main1() {
    int score;
    while (cin >> score) {
        if (score > 100 or score < 0) {
            cout << "Score is error!";
        }
        else {
            if (score > 89) {
                cout << "A";
            }
            else if (score > 79) {
                cout << "B";
            }
            else if (score > 69) {
                cout << "C";
            }
            else if (score > 59) {
                cout << "D";
            }
            else {
                cout << "E";
            }
        }
        cout << '\n';
    }
    return 0;
}