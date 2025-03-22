#include <iostream>
#include <queue>
using namespace std;
bool road[31][31];
bool vis[31][31];
int dx[]={0,0,1};
int dy[]={0,1,0};
struct pos{
    int x,y;
};
queue <pos> dfs;
int ans;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int main(){
    int a=read(),b=read();
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            road[i][j]=1;
        }
    }
    int n=read();
    int tmpx,tmpy;
    for(int i=1;i<=n;i++){
        tmpx=read();tmpy=read();
        road[tmpx][tmpy]=0;
    }
    pos tmp;
    dfs.push(pos{1,1});
    while(!dfs.empty()){
        tmp=dfs.front();
        dfs.pop();
        if(tmp.x==a and tmp.y==b){
            ans++;
            continue;
        }
        for(int i=1;i<=2;i++){
            if(road[tmp.x+dx[i]][tmp.y+dy[i]]){
                dfs.push(pos{tmp.x+dx[i],tmp.y+dy[i]});
            }
        }
    }
    cout<<ans;
}