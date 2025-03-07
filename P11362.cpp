#include <iostream>
#include <stdint.h>
#include <algorithm>

#define debug 0

using namespace std;
typedef unsigned long long ll;
#define mod ll(1e9+7)

struct cd{
    ll c,d;
};
bool cmp(cd a,cd b){
    return (a.c!=b.c)? a.c<b.c : a.d<b.d;
}
cd lis[1000005];
#if debug
uint64_t fv(uint64_t a, uint64_t b) {
    b %= mod - 1;
    uint64_t s = 1;
    while (b) {
        if (b & 1)s *= a, s %= mod;
        a *= a;a %= mod;
        b >>= 1;
    }
    return s % mod;
}
#else
ll fv(ll v,ll x){
    x%=(mod-1);
    ll base=v,ans=1;
    while(x){
        if(x%2){
            ans=(ans*base+mod)%mod;
        }
        base*=base;
        base%=mod;
        x/=2;
    }
    return (ans + mod) % mod;
}
#endif

int main(){
    freopen("input6.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    //cout<<fv(3,5);
    ll T,n,m,v;
    bool flag;
    scanf("%lld",&T);
    for(int to=1;to<=T;to++){
        scanf("%lld%lld%lld",&n,&m,&v);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&lis[i].c,&lis[i].d);
        }
        flag=0;
        sort(lis+1,lis+m+1,cmp);
        for(int i=2;i<=m;i++){
            if(lis[i].c==lis[i-1].c && lis[i].d!=lis[i-1].d){
                puts("0");flag=1;break;
            }
        }
        if(flag){
            continue;
        }
        //ll fis=fv(v,2*(lis[1].c - 1+(n - lis[m].c)));
        ll sec=1;
        for(int i=2;i<=m;i++){
            if (lis[i].c == lis[i - 1].c)
            {
                continue;
            }
            sec*=(fv(v, 2 * (lis[i].c - lis[i - 1].c)) - fv(v, lis[i].c - lis[i - 1].c - 1) * (v - 1) % mod + mod)%mod;
            sec%=mod;
            //sec=(sec*(fv(v,2*(lis[i].c-lis[i-1].c))-fv(v,lis[i].c-lis[i-1].c)+fv(v,lis[i].c-lis[i-1].c-1))+mod)%mod;
        }
        //sec *= (fv(v,2*(lis[1].c - 1+(n - lis[m].c))) + mod) % mod;
        sec *= fv(v, 2 * (lis[1].c - 1)) + mod;
        sec %= mod;
        sec *= fv(v, 2 * (n - lis[m].c)) + mod;
        sec %= mod;
        printf("%llu\n",(sec+mod)%mod);
    }
    return 0;
}