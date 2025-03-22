#include <iostream>
#include <cstring>
using namespace std;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
const int maxn=int(1e4+5);
const int mod=int(1e9+7);
int dp[maxn][maxn][2];//0 1 lst
int max(int a,int b,int c){
    return max(a,max(b,c));
}
int main(){
    int t=read();
    int n,m;
    while(t--){
        n=read();
        m=read();
        if(n==0 or m==0){
            printf("1\n");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][0][0]=1;
        }
        for(int i=0;i<=m;i++){
            dp[0][i][1]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j][0]+=(dp[i-1][j][1]+1+dp[i-1][j][0]);
                dp[i][j][0]%=mod;
                dp[i][j][1]+=(dp[i][j-1][0]+1+dp[i][j-1][1]);
                dp[i][j][1]%=mod;
            }
        }
        printf("%d\n",(dp[n][m][0]+dp[n][m][1])%mod);
    } 
    return 0;     
}