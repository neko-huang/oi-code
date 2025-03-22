#include <iostream>
#include <string.h>
using namespace std;
string otto[5][10]={
    {"XXX","..X","XXX","XXX","X.X","XXX","XXX","XXX","XXX","XXX"},
    {"X.X","..X","..X","..X","X.X","X..","X..","..X","X.X","X.X"},
    {"X.X","..X","XXX","XXX","XXX","XXX","XXX","..X","XXX","XXX"},
    {"X.X","..X","X..","..X","..X","..X","X.X","..X","X.X","..X"},
    {"XXX","..X","XXX","XXX","..X","XXX","XXX","..X","XXX","XXX"}
};
int main(){
    int n;cin>>n;
    string num;cin>>num;
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            cout<<otto[i][num[j]-'0'];
            if(j!=n-1){
                cout<<'.';
            }
        }
        cout<<'\n';
    }
    return 0;
}