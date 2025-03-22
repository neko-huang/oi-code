#include <iostream>
#include <vector>
using namespace std;
const int maxn=int(5e5+5);
int siz[maxn],top[maxn],dep[maxn];
int fa[maxn],son[maxn],dfn[maxn],dfs[maxn];
vector <int> graph[maxn];
int dfstot;
void dfs1(int x,int father,int depth){
    dep[x]=depth;
    fa[x]=father;
    siz[x]=1;
    int tmp=-1;
    for(int i=0;i<graph[x].size();i++){
        if(graph[x][i]!=fa[x]){
            dfs1(graph[x][i],x,depth+1);
            siz[x]+=siz[graph[x][i]];
            if(siz[graph[x][i]]>tmp){
                tmp=siz[graph[x][i]];
                son[x]=graph[x][i];
            }
        }
    }
}
void dfs2(int x,int nowtop){
    top[x]=nowtop;
    dfn[x]=++dfstot;
    dfs[dfstot]=x;
    if(son[x]){
        dfs2(son[x],nowtop);
        for(int i=0;i<graph[x].size();i++){
            if(graph[x][i]!=fa[x] and graph[x][i]!=son[x]){
                dfs2(graph[x][i],graph[x][i]);
            }
        }
    }
}
int sec(int a,int b,int c){
    dep[0]=-1;
    int large=0,slarge=0;
    if(dep[large]<dep[a]){
        slarge=large;
        large=a;
    }else if(dep[large]>dep[a] and dep[a]>dep[slarge]){
        slarge=a;
    }

    if(dep[large]<dep[b]){
        slarge=large;
        large=b;
    }else if(dep[large]>dep[b] and dep[b]>dep[slarge]){
        slarge=b;
    }

    if(dep[large]<dep[c]){
        slarge=large;
        large=c;
    }else if(dep[large]>dep[c] and dep[c]>dep[slarge]){
        slarge=c;
    }
    return slarge;
}
int max(int a,int b,int c){
    dep[0]=-1;
    int large=0;
    if(dep[large]<dep[a]){
        large=a;
    }

    if(dep[large]<dep[b]){
        large=b;
    }

    if(dep[large]<dep[c]){
        large=c;
    }
    return large;
}
int min(int a,int b,int c){
    dep[0]=0x3f3f3f3f;
    int large=0;
    if(dep[large]>dep[a]){
        large=a;
    }

    if(dep[large]>dep[b]){
        large=b;
    }

    if(dep[large]>dep[c]){
        large=c;
    }
    return large;
}
int LCA(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]>dep[top[b]]){
            a=fa[top[a]];
        }
        else{
            b=fa[top[b]];
        }
    }
    return dep[a]>dep[b]?b:a;
}
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
int dis(int a,int b){
    return dep[a]+dep[b]-2*dep[LCA(a,b)];
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<n;i++){
        int a=read(),b=read();
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int x,y,z;
    while(m--){
        x=read();y=read();z=read();
        int nx=x,ny=y,nz=z;
        int highpoint=min(x,y,z);
        while(top[highpoint]!=top[x]){
            x=fa[top[x]];
        }
        while(top[highpoint]!=top[y]){
            y=fa[top[y]];
        }
        while(top[highpoint]!=top[z]){
            z=fa[top[z]];
        }
        int ans=sec(x,y,z);
        printf("%d %d\n",ans,dis(nx,ans)+dis(ny,ans)+dis(nz,ans));
    }
}