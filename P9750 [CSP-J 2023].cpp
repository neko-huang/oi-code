#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
bool issqrt(ll a){
    ll dd=sqrt(a);
    if(dd*dd==a){
        return 1;
    }
    return 0;
}
ll fsqrt(ll a){
    ll i=1;
    for(;i*i<=a;i++){
        if(a%(i*i)==0){
            return i;
        }
    }
    return -1;
}
int main(){
    ll k;
    cin>>k;
    ll a,b,c;
    for(int i=1;i<=k;i++){
        cin>>a>>b>>c;
        ll delta=b*b-4*a*c;
        ll q=2*a;
        if(delta<0){
            cout<<'NO\n';
            continue;
        }
        if(issqrt(delta)){
            if((-b+ll(sqrt(delta)))%q==0){
                cout<<(-b+ll(sqrt(delta)))/q<<endl;
                continue;
            }
            else{
                cout<<(-b+ll(sqrt(delta)))<<'/'<<q<<endl;
                continue;
            }
        }
        if(b!=0){
            if((-b)%q==0){
                cout<<(-b)/q<<"+";
            }
            else{
                cout<<(-b)<<'/'<<q<<"+";
            }
        }
        ll eas=fsqrt(delta);
    }
}