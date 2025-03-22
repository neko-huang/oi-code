#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
struct item{
    int a,b;
};
vector <item> bag[127];
int dp[1023];
int ans;
int main(){
    int n,m;int a,b,c;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        bag[c].push_back(item{a,b});
    }
    for(int k=1;k<=100;k++){
        if(!bag[k].empty()){
            //memset(dp,0,sizeof(dp));
            for(int j=m;j>=0;j--){
                for(int i=0;i<bag[k].size();i++){
                    if(j>=bag[k][i].a){
                        dp[j]=max(dp[j],dp[j-bag[k][i].a]+bag[k][i].b);
                    }
                }
            }//ans=max(ans,dp[m]);
        }
    }
    cout<<dp[m];
    return 0;
}