#include <iostream>
using namespace std;
int f[1005];
int main(){
    int n;
    cin>>n;
    f[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j*2<=i;j++){
            f[i]+=f[j];
        }
        f[i]++;
    }
    cout<<f[n];
}