#include <iostream>
#include <vector>
#define mod 10007
using namespace std;
vector <int> tree[200005];
int w[200005];
int ans1,ans2;
bool vis[200005];
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int fis=0,sec=0;
        int f1=0,f2=0;
        if(tree[i].size()>1){
            for(int j=0;j<tree[i].size();j++){
                if(w[tree[i][j]]>=fis){
                    sec=fis;
                    fis=w[tree[i][j]];
                }
                else if(w[tree[i][j]]>=sec){
                    sec=w[tree[i][j]];
                }
                f1=(f1+w[tree[i][j]]+mod)%mod;
                f2=(f2+w[tree[i][j]]*w[tree[i][j]]+mod)%mod;
            }
            ans2=max(ans2,fis*sec);
            ans1=(ans1+f1*f1-f2+mod)%mod;
        }
    }
    cout<<ans2<<' '<<ans1;
}