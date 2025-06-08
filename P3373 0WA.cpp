#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn=100000;
//-----------------
struct node{
    ll l,r,sum=0;
    ll lzt=0,flzt=1;
};
node tree[4*maxn+5];
ll a[maxn+5];
ll q;
//----------------------
ll pow(ll a,ll x){
    a%=q;ll ans=1;
    while(x){
        if(x%2){
            ans=(ans*a+q)%q;
        }
        a=a*a%q;
        x/=2;
    }
    return ans;   
}
void build_tree(ll x,ll sl,ll sr){
    ll mid=(sl+sr)/2;
    tree[x].l=sl;
    tree[x].r=sr;
    if(sl==sr){
        tree[x].sum=a[sl]%q;
        return ;
    }
    build_tree(x*2,sl,mid);
    build_tree(x*2+1,mid+1,sr);
    tree[x].sum=(tree[x*2].sum+tree[x*2+1].sum)%q;
    return;
}
void pushdown_f(ll x){
    if (tree[x].flzt!=1)
    {
        tree[x*2].sum*=tree[x].flzt;
        tree[x*2].sum%=q;
        tree[x*2+1].sum*=tree[x].flzt;
        tree[x*2+1].sum%=q;
        tree[x*2].flzt*=tree[x].flzt;
        tree[x*2].flzt%=q;
        tree[x*2+1].flzt*=tree[x].flzt;
        tree[x*2+1].flzt%=q;
        tree[x].flzt=1;
    }
    return;
    
}
void pushdown(ll x){
    if (tree[x].lzt)
    {
        tree[x*2].sum+=(tree[x*2].r-tree[x*2].l+1)*tree[x].lzt;
        tree[x*2].sum%=q;
        tree[x*2+1].sum+=(tree[x*2+1].r-tree[x*2+1].l+1)*tree[x].lzt;
        tree[x*2+1].sum%=q;
        tree[x*2].lzt+=tree[x].lzt;
        tree[x*2].lzt%=q;
        tree[x*2+1].lzt+=tree[x].lzt;
        tree[x*2+1].lzt%=q;
        tree[x].lzt=0;
    }
    return;
    
}
void add(ll u,ll x,ll al,ll ar){
    if(tree[x].l>=al and tree[x].r<=ar){
        tree[x].lzt+=u;
        tree[x].lzt%=q;
        tree[x].sum+=u*(tree[x].r-tree[x].l+1);
        tree[x].sum%=q;
        return ;
    }
    ll mid=(tree[x].l+tree[x].r)/2;
    //tree[x].lzt+=u;
    pushdown(x);
    if (mid >= al)
    {
        add(u,x*2,al,ar);
    }
    if (mid < ar)
    {
        add(u,x*2+1,al,ar);
    }
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    tree[x].sum%=q;
}
void frot(ll u,ll x,ll al,ll ar){
    if(tree[x].l>=al and tree[x].r<=ar){
        tree[x].flzt*=u;
        tree[x].flzt%=q;
        tree[x].sum*=u;
        tree[x].sum%=q;
        return ;
    }
    ll mid=(tree[x].l+tree[x].r)/2;
    //tree[x].lzt+=u;
    pushdown_f(x);
    if (mid >= al)
    {
        frot(u,x*2,al,ar);
    }
    if (mid < ar)
    {
        frot(u,x*2+1,al,ar);
    }
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    tree[x].sum%=q;
}
ll check(ll x,ll al,ll ar){
    if(tree[x].l>=al and tree[x].r<=ar){
        return tree[x].sum;
    }
    pushdown(x);
    pushdown_f(x);
    ll mid=(tree[x].l+tree[x].r) >> 1, sum = 0;
    //tree[x].lzt+=u;
    if (mid >= al)
    {
        sum += check(x*2,al,ar);
    }
    if (mid < ar)
    {
        sum += check(x*2 + 1,al,ar);
    }    
    
    return sum;
}
int main(){
    ll n,m;
    scanf("%lld%lld%lld",&n,&m,&q);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    ll x,y,k,tmp;
    build_tree(1,1,n);
    while(m--){
        scanf("%lld",&tmp);
        if(tmp==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            frot(k%q,1,x,y);
        }
        else if(tmp==2){
            scanf("%lld%lld%lld",&x,&y,&k);
            add(k%q,1,x,y);
        }
        else{
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",check(1,x,y)%q);
        }
    }
    return 0;
}