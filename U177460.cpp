#include <iostream>
#include <vector>
using namespace std;
vector <int> vt[10];
bool isvis[10];
//int pat[10],now=0;
int ans=0,n,m;
void dfs(int x){
    for(int i=0;i<vt[x].size();i++){
        if(!isvis[vt[x][i]] and vt[x][i]!=1){
            isvis[vt[x][i]]=1;//now++;pat[now]=vt[x][i];
            dfs(vt[x][i]);
            isvis[vt[x][i]]=0;//now--;
        }
    }
    for(int i=2;i<=n;i++){
        if(!isvis[i]){
            return ;
        }
    }
    /*for(int i=1;i<=n-1;i++){
        cout<<pat[i]<<' ';
    }
    cout<<endl;*/
    ans++;
    return ;
}
int main(){
    int va,vb;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>va>>vb;
        vt[va].push_back(vb);
        vt[vb].push_back(va);
    }
    dfs(1);
    cout<<ans;
    return 0;
}