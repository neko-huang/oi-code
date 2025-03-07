#include <iostream>
using namespace std;
const int maxn=int(1e5+5);   
#define ls s[0]
#define rs s[1]
struct node{
    int s[2]={0,0};
    int fa=0,sz=0;
    int cnt=0;
}tree[maxn];
int rt=0;
int idx=0;
int newnode(int x){
    tree[++idx].cnt=x;
    tree[idx].sz=1;
    return idx;
}
bool get(int x){
    return tree[tree[x].fa].rs==x;
}
void upd(int x){
    tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
}
void rotate(int x){
    int f=tree[x].fa,gf=tree[f].fa,c=get(x);
    tree[f].s[c]=tree[x].s[!c];
    if(tree[x].s[!c]){
        tree[tree[x].s[!c]].fa=f;
    }
    tree[x].s[!c]=f;
    tree[f].fa=x;
    if(gf){
        tree[gf].s[f==tree[gf].ls]=x;
    }
    upd(f);
    upd(x);
    return ;
}
void splay(int x){
    for(int f=tree[x].fa;f=tree[x].fa,f;rotate(x)){
        if(tree[f].fa){
            rotate(get(x)==get(f)?f:x);
        }
    }
    rt=x;
}
void ins(int x){
    int now=rt,f=0;
    while(now){
        f=now,now=tree[now].s[x>tree[now].cnt];
    }
    now=newnode(x);
    tree[now].fa=f;
    tree[f].s[x>tree[now].cnt]=now;
    splay(now);
}
void del(int x){
    int now=rt,p=0;
}