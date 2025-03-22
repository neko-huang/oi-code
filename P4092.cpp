#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn=int(2e5+5);
const ll lowinf=-1 ;
ll fa[maxn],dp[maxn],size1[maxn],son[maxn];// father deep size1
ll top[maxn],dfn[maxn],dfs[maxn];
ll head[maxn];
struct eedge{
    ll next=0,to=0;
};
/*
void swap(ll &a,ll &b){
    ll tmp=a;
    a=b;
    b=tmp;
}
*/
eedge edge[maxn];
ll itt=1;
void addge(ll u,ll v){
    edge[itt].to=v;
    edge[itt].next=head[u];
    head[u]=itt++;
}
struct node{
    ll l,r;
    ll d;
};
node tree[maxn*4];
ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c>'9' or c<'0'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=igt*10+c-'0';
        c=getchar();
    }
    return igt*sgn;
}
void dfs1(ll x,ll fat,ll dep){
    dp[x]=dep;
    fa[x]=fat;
    size1[x]=1;
    ll tmp=lowinf;
    for(ll i=head[x];i;i=edge[i].next){
        if(edge[i].to!=fat){
            dfs1(edge[i].to,x,dep+1);
            size1[x]=size1[x]+size1[edge[i].to];
            if(tmp<size1[edge[i].to]){
                tmp=size1[edge[i].to];
                son[x]=edge[i].to;
            }
        }
    }
}
ll tot;
void dfs2(ll x,ll top1){
    top[x]=top1;
    dfn[x]=++tot;
    dfs[tot]=x;
    if(son[x]){
        dfs2(son[x],top1);
        for(ll i=head[x];i;i=edge[i].next){
            if(edge[i].to!=fa[x] and edge[i].to!=son[x]){///
                dfs2(edge[i].to,edge[i].to);//chong huo xin sheng!
            }
        }
    }
}
void upd(ll x){
    tree[x].d=max(tree[x*2].d,tree[x*2+1].d);
    return ;
}
void build(ll x,ll bl,ll br){
    tree[x].l=bl;
    tree[x].r=br;
    tree[x].d=lowinf;
    if(bl==br){//
        return ;
    }
    ll mid=(bl+br)/2;
    build(x*2,bl,mid);
    build(x*2+1,mid+1,br);//
    return ;
}
void modify(ll x,ll ml,ll mr){
    if(ml<=tree[x].l and tree[x].r<=mr){
        tree[x].d=ml;///
        return ;
    }
    ll mid=(tree[x].l+tree[x].r)/2;
    if(ml<=mid){//
        modify(x*2,ml,mr);
    }
    if(mr>mid){
        modify(x*2+1,ml,mr);
    }
    upd(x);
    return ;
}
ll query(ll x,ll ql,ll qr){
    if(ql<=tree[x].l and tree[x].r<=qr){
        return tree[x].d;
    }
    ll mid=(tree[x].l+tree[x].r)/2;
    ll ans=lowinf;
    if(ql<=mid){//
        ans=max(ans,query(x*2,ql,qr));
    }
    if(qr>mid){
        ans=max(ans,query(x*2+1,ql,qr));
    }
    return ans;
}
bool check[maxn];
int main(){
    memset(head,-1,sizeof(head));
    ll n=read(),q=read();//misuzu!  
    ll u,v;
    for(ll i=1;i<n;i++){
        u=read(),v=read();
        addge(u,v);
        addge(v,u);
    }
    dfs1(1,0,1);//666
    dfs2(1,1);
    //hai you ixna duan shu
    build(1,1,n);
    modify(1,1,1);
    bool flag=0;
    char opt;ll qc;
    check[1]=1;
    for(ll i=1;i<=q;i++){
        cin>>opt;
        flag=0;
        qc=read();
        if(opt=='C'){
            if(!check[i]){
                modify(1,dfn[qc],dfn[qc]);
            }
            check[i]=1;
        }
        else{
            ll ret=lowinf;
            ll u=qc,v=1;
            while(top[u]!=top[v]){
                if(dp[dfn[u]]<dp[dfn[v]]){
                    swap(u,v);
                }
                ret=query(1,dfn[top[u]],dfn[u]);
                if(ret!=lowinf){
                    printf("%d\n",dfs[ret]);
                    flag=1;
                    break;
                }
                u=fa[top[u]];///
            }
            if(flag){
                continue;
            }
            if(dp[u]>dp[v]){
                swap(u,v);
            }
            ret=query(1,dfn[u],dfn[v]);
            printf("%d\n",dfs[ret]);
        }
    }
    return 0;
}