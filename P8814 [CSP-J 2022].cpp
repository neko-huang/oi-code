#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
bool issqrt(ll a){
    if(ll(sqrt(a))*ll(sqrt(a))==a){
        return 1;
    }
    return 0;
}
int main(){
    //freopen("test.in","r",stdin);
    //freopen("test1.out","w",stdout);
    //cout<<issqrt(177244);
    ll k,n,e,d;
    cin>>k;
    for(ll i=1;i<=k;i++){
        cin>>n>>d>>e;
        ll plus1=n-e*d+2;
        ll del2=plus1*plus1-4*n;
        if(!issqrt(del2)){
            cout<<"NO\n";
            continue;
        }
        ll p=plus1-sqrt(del2);
        if(p%2==1){
            cout<<"NO\n";
            continue;
        }
        cout<<p/2<<' '<<p/2+ll(sqrt(del2))<<'\n';
    }
    return 0;
}