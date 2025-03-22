#include <iostream>
using namespace std;
const int maxn=200005;
int sc[maxn];
struct node{
    int l,r;
    int maxs;
};
node tree[maxn*4];
inline int read(){
    int n;
    scanf("%d",&n);
    return n;
}
void upd(int x){
    tree[x].maxs=max(tree[x*2].maxs,tree[x*2+1].maxs);
}
void build(int bl,int br,int x){
    tree[x].l=bl;
    tree[x].r=br;
    if(bl==br){
        tree[x].maxs=sc[bl];
        return ;
    }
    int mid=(bl+br)/2;
    build(bl,mid,x*2);
    build(mid+1,br,x*2+1);
    upd(x);
    return ;
}
void addset(int id,int x,int n){
    if(tree[x].l==tree[x].r and tree[x].l==id){
        if(tree[x].maxs<n){
            tree[x].maxs=n;
        }
        return ;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    if(id<=mid){
        addset(id,x*2,n);
        upd(x);
    }
    if(id>mid){
        addset(id,x*2+1,n);
        upd(x);
    }
    return ;
}
int query(int ql,int qr,int x){
    if(ql<=tree[x].l and qr>=tree[x].r){
        return tree[x].maxs;     
    }
    int mid=(tree[x].l+tree[x].r)/2;
    int tp=0;
    if(mid>=ql){
        tp=max(query(ql,qr,x*2),tp);
    }
    if(mid<qr){
        tp=max(query(ql,qr,x*2+1),tp);
    }
    return tp;
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        sc[i]=read();
    }
    build(1,n,1);
    char opt[100];int sl,sr;
    while(m--){
        scanf("%s%d%d",opt,&sl,&sr);
        if(opt[0]=='Q'){
            printf("%d\n",query(sl,sr,1));
        }
        if(opt[0]=='U'){
            addset(sl,1,sr);
        }
    }
    return 0;
}