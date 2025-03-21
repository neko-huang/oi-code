#include <iostream>
using namespace std;
int dp[1023];
int T[127];
int V[127];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>T[i]>>V[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=t;j>=T[i];j--){
            dp[j]=max(dp[j],dp[j-T[i]]+V[i]);
        }
    }
    cout<<dp[t];
}