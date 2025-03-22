#include <iostream>
using namespace std;
int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c>='0' and c<='9'){
        igt=igt*10+c-'0';
        c=getchar();
    }
    return igt*sgn;
}
const int maxn=277;
const int maxk=int(1e9+7);
int maze[maxn][maxn];
bool rec[maxn][maxn][maxk];
char recnum[maxn][maxn];
int dx[]={0,0,1,0,1};
int dy[]={0,0,0,1,1};
int main(){
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            maze[i][j]=read();
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            for(int k=1;k<=4;k++){
                rec[i][j][maze[i+dx[k]][j+dx[k]]]=1;
                recnum[i][j]++;
            }
        }
    }
    recnum[0][0]=0x3f;
    int minx=0,miny=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(recnum[minx][miny]>recnum[i][j]){
                minx=i;miny=j;
            }
        }
    }
    int tmpcolor,tmpcolornum=0,tmp=0;
    for(int i=1;i<=k;i++){
        tmp=0;
        for(int j=1;j<=4;j++){
            if(rec[minx-dx[j]][miny-dy[j]][i]==0){
                tmp++;
            }
        }
        if(tmp>tmpcolornum){
            tmpcolornum=tmp;
            tmpcolor=i;
        }
    }
    for(int i=1;i<=4;i++){
        if(rec[minx-dx[i]][miny-dy[i]][tmpcolor]==0){
            recnum[minx-dx[i]][miny-dy[i]]++;
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(recnum[i][j]>=3){
                ans++;
            }
        }
    }
    cout<<ans;
}