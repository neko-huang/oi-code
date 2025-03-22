#include <iostream>
#include <algorithm>
using namespace std;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int c[31];
int cat[31];
int n,w;
int ret=0x3f3f3f3f;
void dfs(int x,int ans){
    if(ans>=ret){
        return ;
    }
    if(x==n+1){
        ret=min(ret,ans);
        return ;
    }
    for(int i=1;i<=ans;i++){
        if(cat[i]+c[x]<=w){
            cat[i]+=c[x];
            dfs(x+1,ans);
            cat[i]-=c[x];
        }
    }
    cat[ans+1]=c[x];
    dfs(x+1,ans+1);
    cat[ans+1]=0;
    return ;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    n=read();
    w=read();
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    sort(c+1,c+n+1,cmp);
    dfs(1,1);
    printf("%d",ret);
    return 0;
}