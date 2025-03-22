#include <iostream>
using namespace std;
const int maxn=100005;
typedef long long ll;
ll p;
ll wow[maxn];//,exwow[maxn];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;return ;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
}
ll pow(ll a,ll x){
    a%=p;ll ans=1;
    while(x){
        if(x%2){
            ans=(ans*a+p)%p;
        }
        a=a*a%p;
        x/=2;
    }
    return ans;   
}
ll c(ll n,ll m){
    if(n<m){
        return 0;
    }
    /*
    ll x1=0,y1=0,x2=0,y2=0;
    exgcd(wow[m],p,x1,y1);
    exgcd(wow[n-m],p,x2,y2);
    */
    return ((wow[n]*pow(wow[m],p-2)+p)%p*pow(wow[n-m],p-2)+p)%p;
}
ll lucas(ll n,ll m){
    if(m==0){
        return 1; 
    }
    return (lucas(n/p,m/p)*c(n%p,m%p)+p)%p;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m>>p;
        n+=m;
        wow[0]=1;
        for(int i=1;i<=p;i++){
            wow[i]=i*wow[i-1]+p;
            wow[i]%=p;
        }
        cout<<lucas(n,m)<<'\n';
    }
}