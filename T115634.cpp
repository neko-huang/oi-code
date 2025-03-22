#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct pos{
    int x,y;
};
int h,w;
char clist[31][31];
bool vis[31][31];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
pos st;
bool ruu;
void in(){
    cin>>w>>h;
    if(w==0 and h==0){
        ruu=1;
        return ;
    }
    for(int i=1;i<=h;i++){
        scanf(" ");
        scanf("\n");
        for(int j=1;j<=w;j++){
            scanf("%1c",&clist[i][j]);
            if(clist[i][j]=='@'){
                st.x=i;st.y=j;
            }
        }
    }
    return ;
}
int main(){
    while(1){
        memset(clist,0,sizeof(clist));
        memset(vis,0,sizeof(vis));
        in();
        if(ruu)return 0;
        queue <pos> bfs;
        bfs.push(st);
        pos tmp;
        int ans=1;
        while(!bfs.empty()){
            tmp=bfs.front();
            bfs.pop();
            for(int i=1;i<=4;i++){
                tmp.x+=dx[i];
                tmp.y+=dy[i];
                if(clist[tmp.x][tmp.y]=='.' and vis[tmp.x][tmp.y]==0){
                    bfs.push(tmp);
                    vis[tmp.x][tmp.y]=1;
                    ans++;
                }    
                tmp.x-=dx[i];
                tmp.y-=dy[i] ;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}