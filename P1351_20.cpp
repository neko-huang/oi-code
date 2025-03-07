#include <iostream>
#include <vector>
#define mod 10007
using namespace std;
vector <int> tree[200005];
int w[200005];
int ans1,ans2;
bool vis[200005];
void dfs(int fis,int n,int x){
    if(x==0){
        int ned=w[fis]*w[n];
        ans2+=(ned+mod)%mod;
        ans1=max(ans1,ned);
        return ;
    }
    for(int i=0;i<tree[n].size();i++){
        if(!vis[tree[n][i]]){
            vis[tree[n][i]]=1;
            dfs(fis,tree[n][i],x-1);
            vis[tree[n][i]]=0;
        }
    }
}
int main(){
    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i,i,2);
        vis[i]=0;
    }
    cout<<ans1<<' '<<ans2;
}