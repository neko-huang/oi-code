#include <iostream>
#include <algorithm>
using namespace std;
int ans=0x3f3f3f3f;
char maze[100][100];
bool vis[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x,int y,int cnt){
    if(x==1 and y==1){
        ans=min(ans,cnt);
        return ;
    }
    for(int i=0;i<4;i++){
        if(maze[x+dx[i]][y+dy[i]]=='.' and vis[x+dx[i]][y+dy[i]]!=1){
            vis[x+dx[i]][y+dy[i]]=1;
            dfs(x+dx[i],y+dy[i],cnt+1);
            vis[x+dx[i]][y+dy[i]]=0;
        }
    }
    return ;
}
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>maze[i][j];
        }
    }
    dfs(m,n,0);
    if(ans==0x3f3f3f3f){
        cout<<"ERROR";
        return 0;
    }
    cout<<ans;
    return 0;
}