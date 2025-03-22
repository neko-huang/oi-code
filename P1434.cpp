#include "iostream"
#include "algorithm"
using namespace std;
struct hill{
    int x,y,high;
};
bool cmp(hill x,hill y){
    return x.high>y.high;
}
int heigth[105][105];
int dp[105][105];
int n,m;
int dx[5]={0x3f3f3f3f,-1,1,0,0};
int dy[5]={0x3f3f3f3f,0,0,1,-1};
hill mountain[10005];
int main(){
    cin>>n>>m;
    int tmp=0;
    for(int i=1;i<=n;i++){
        for(int p=1;p<=m;p++){
            cin>>heigth[i][p];
            dp[i][p]=1;
            mountain[++tmp]={i,p,heigth[i][p]};
        }
    }
    sort(mountain+1,mountain+1+tmp,cmp);
    for(int j=1;j<=tmp;j++){
        int i=mountain[j].x,p=mountain[j].y;
        for(int tpget=1;tpget<=4;tpget++){
            if(heigth[i+dx[tpget]][p+dy[tpget]]>heigth[i][p]){
                dp[i][p]=max(dp[i][p],dp[i+dx[tpget]][p+dy[tpget]]+1);
            }
         }
    }
            
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int p=1;p<=m;p++){
            ans=max(ans,dp[i][p]);
        }
    }
    cout<<ans;
}