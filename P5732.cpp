#include <iostream>
using namespace std;
int C[31][31];
int main(){
    int n;
    cin>>n;
    C[1][1]=1;
    cout<<"1\n";
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            C[j][i]=C[j-1][i-1]+C[j][i-1];
            cout<<C[j][i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}