#include <iostream>
using namespace std;
int a[100005];
int main(){
    int n,x;long long ans=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]+a[i+1]>x){
            ans+=(a[i]+a[i+1]-x);
            a[i+1]-=(a[i]+a[i+1]-x);
        }
    }
    cout<<ans;
    return 0;
}