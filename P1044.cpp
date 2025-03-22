#include <iostream>
using namespace std;
int f[31];
int main(){
    int n;cin>>n;
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i]+=f[j-1]*f[i-j];
        }
    }
    cout<<f[n];
}