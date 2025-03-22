#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>
#define inf 0x3f3f3f3f
using namespace std;
struct pos{
    int x,y;
};
int n,m;
int maze[1005][1005],visit[1005][1005];
int deltax[5]={inf,0,0,-1,1};
int deltay[5]={inf,1,-1,0,0};
bool byd(pos position,int tryn){
    queue <pos> gogo;
    gogo.push(position);
    visit[position.x][position.y]=1;
    while(!gogo.empty()){
        for(int i=1;i<=4;i++){
            int xx=gogo.front().x+deltax[i];
            int yy=gogo.front().y+deltay[i];
            if(visit[xx][yy] or maze[xx][yy]>tryn)continue;
            visit[xx][yy]=1;
            if(xx==n){
                return 1;//ke yi dao
            }
            else{
                gogo.push({xx,yy});
            }
        }
        gogo.pop();
    }
    return 0;
}
void basicset(){
    for(int i=0;i<1005;i++){
        for(int p=0;p<1005;p++){
            maze[i][p]=inf;
        }
    }
    return ;
}
int main(){ 
    cin>>n>>m;
    basicset();
    for(int i=1;i<=n;i++){
        for(int p=1;p<=m;p++){
            cin>>maze[i][p];
        }
    }
    int left=1,right=int(1e9);int wowans;
    while(left<=right){
        int mid=(left+right)/2;
        memset(visit,0x00000000,sizeof(visit));
        if(byd({1,1},mid)){//niguoguan
            right=mid-1;
            wowans=mid;
        }
        else{
            left=mid+1;
        }
    }
    cout<<wowans;
    return 0;
}