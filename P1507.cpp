#include <iostream>
using namespace std;
const int maxn=63;
int h[maxn],t[maxn],k[maxn];
int dp[511][511];
int main(){
    int mh,mt;
    cin>>mh>>mt;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>t[i]>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=mh;j>=h[i];j--){
            for(int f=mt;f>=t[i];f--){
                dp[j][f]=max(dp[j][f],dp[j-h[i]][f-t[i]]+k[i]);
            }
        }
    }
    cout<<dp[mh][mt];
}