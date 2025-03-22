#include <stdio.h>
using namespace std;
typedef long long ll;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;return ;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
}
ll rev(ll a,ll p){
    ll x,y;
    exgcd(a,p,x,y);
    return (x+p)%p;
}
ll nowr[3000005];
int main(){
    ll n,p;
    scanf("%lld%lld",&n,&p);
    nowr[1]=1;
    printf("1\n");
    for(ll i=2;i<=n;i++){
        nowr[i]=(p-p/i)*nowr[p%i];
        nowr[i]%=p;
        printf("%lld\n",nowr[i]);
    }
}