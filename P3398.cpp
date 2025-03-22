#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
const int maxn=int(1e6+5);
int siz[maxn],fa[maxn],top[maxn];
int dep[maxn],son[maxn],dfn[maxn],dfs[maxn];
vector <int> graph[maxn];
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
int tot;
void dfs1(int x,int father,int depth){
    dep[x]=depth;
    fa[x]=father;
    siz[x]=1;
    int tmp=-1;
    for(int i=0;i<graph[x].size();i++){
        if(graph[x][i]!=father){
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
    dfn[x]=++tot;
    dfs[tot]=x;
    if(son[x]){
        dfs2(son[x],nowtop);
        for(int i=0;i<graph[x].size();i++){
            if(graph[x][i]!=fa[x] and graph[x][i]!=son[x]){
                dfs2(graph[x][i],graph[x][i]);
            }
        }
    }
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
int dis(int a,int b){
    int c=LCA(a,b);
    return dep[a]+dep[b]-2*dep[c];
}
int main(){
    int n=read(),m=read();
    int tmpu,tmpv;
    int a,b,c,d;
    for(int i=1;i<n;i++){
        tmpu=read(),tmpv=read();
        graph[tmpu].push_back(tmpv);
        graph[tmpv].push_back(tmpu);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1;i<=m;i++){
        a=read();b=read();c=read();d=read();
        int x=LCA(a,b),y=LCA(c,d);
        if((dis(a,y)+dis(b,y)==dis(a,b)) or (dis(c,x)+dis(d,x)==dis(c,d))){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}