#include <iostream>
using namespace std;
int dp[10005],a[1023];
#define mod (int(1e9+7))
int main(){
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=n;j++){
            if(a[j]<=i){
                dp[i]+=dp[i-a[j]];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[w];
}