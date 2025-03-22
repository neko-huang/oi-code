#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll ans=1<<30;
    for(ll i=1;i<10;i++){
        for(ll j=100;j<500;j++){
            for(ll k=100;k<500;k++){
                if((i*j*k)==(i*i+j*j+k*k-8)){
                    ans=min(ans,i*j*k);
                }
            }
        }
    }
    cout<<ans;
}
