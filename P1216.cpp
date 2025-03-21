#include <iostream>
using namespace std;
#define maxn 1023
int dp[maxn][maxn];
int pir[maxn][maxn];
int main(){
    int r;
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>pir[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=r;j++){
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1])+pir[i][j]);
        }
    }
    int ans=0;
    for(int i=1;i<=r;i++){
        ans=max(ans,dp[r][i]);
    }
    cout<<ans;
    return 0;
}