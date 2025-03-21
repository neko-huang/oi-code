#include <iostream>
#include <cstring>
using namespace std;
int dp[10004],a[1004];
int main(){
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=n;j++){
            if(a[j]<=i)dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }
    cout<<dp[w];
    return 0;
}