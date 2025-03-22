#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=200005;
struct node{
    int l,r;
    ll sum,lzt;
};
node tree[4*maxn];
ll a[maxn];
void upd(int x){
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
void pushdown(int x){
    if(tree[x].lzt){
        tree[x*2].lzt+=tree[x].lzt;
        tree[x*2+1].lzt+=tree[x].lzt;
        tree[x*2].sum+=(tree[x*2].r-tree[x*2].l+1)*tree[x].lzt;
        tree[x*2+1].sum+=(tree[x*2+1].r-tree[x*2+1].l+1)*tree[x].lzt;
        tree[x].lzt=0;
    }
    return ;
}
void build_tree(int x,int bl,int br){
    tree[x].l=bl;
    tree[x].r=br;
    tree[x].lzt=0;
    if(bl==br){
        tree[x].sum=a[bl];
        return ;
    }
    int mid=(bl+br)/2;
    build_tree(x*2,bl,mid);
    build_tree(x*2+1,mid+1,br);
    upd(x);
    return ;
}
void add(int x,int al,int ar,int n){
    if(al<=tree[x].l and tree[x].r<=ar){
        tree[x].sum+=n*(tree[x].r-tree[x].l+1);
        tree[x].lzt+=n;
        return ;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    pushdown(x);
    if(al<=mid){
        add(x*2,al,ar,n);
    }
    if(ar>mid){
        add(x*2+1,al,ar,n);
    }
    upd(x);
    return ;
}
ll query(int x,int ql,int qr){
    if(ql<=tree[x].l and tree[x].r<=qr){
        return tree[x].sum;
    }
    int mid=(tree[x].l+tree[x].r)/2;ll ret=0;
    pushdown(x);
    if(ql<=mid){
        ret+=query(x*2,ql,qr);
    }
    if(qr>mid){
        ret+=query(x*2+1,ql,qr);
    }
    return ret;
}
int main(){
    int n,f;
    cin>>n>>f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build_tree(1,1,n);
    int opt,l,r,k;
    while(f--){
        cin>>opt;
        if(opt==1){
            cin>>l>>r>>k;
            add(1,l,r,k);
        }
        else if(opt==2){
            cin>>k;
            add(1,1,1,k);
        }
        else if(opt==3){
            cin>>k;
            add(1,1,1,-k);
        }
        else if(opt==4){
            cin>>l>>r;
            cout<<query(1,l,r)<<'\n';
        }
        else{
            cout<<query(1,1,1)<<'\n';
        }
    }
    return 0;
}