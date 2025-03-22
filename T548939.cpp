#include <iostream>
#include <cstring>
using namespace std;
const int maxn=int(1e7+5);
const int mod=998244353;
bool dp[maxn][maxn];//2 way 1:start! 2:length
int a[maxn];
int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c-getchar();
    }
    while(c>='0' and c<='9'){
        igt=igt*10+c-'0';
        c=getchar();
    }
    return igt*sgn;
}
int ans;
void init(){
    memset(dp,0,sizeof(dp));
    ans=0;
    return ;
}
void dfs(int n,int x){
    if(n==0){
        if(x==0){
            ans++;
        }
        return ;
    }
    
}
int main(){
    int t=read();
    int n,m;
    while(t--){
        n=read();m=read();
        init();
        for(int i=1;i<=n;i++){
            a[i]=read();
            dp[a[i]][1]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[a[i]][j-i] and a[j-i]<a[j-i+1]){
                    dp[a[i]][j-i+1]=1;
                }
            }
        }

    }
}