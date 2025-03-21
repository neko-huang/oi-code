#include <iostream>
using namespace std;
#define mod (int(1e9+7))
int dp[1023],a[10004];
int main(){
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=w;j++){
            dp[j]+=dp[j-a[i]];
            dp[j]%=mod;
        }
    }
    cout<<dp[w];
    return 0;
}