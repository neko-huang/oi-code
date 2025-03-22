#include <iostream>
using namespace std;
typedef long long ll;
ll cl[625];
ll cac(ll n){
    return n*n*n;
}
int main(){
    ll n;
    cin>>n;
    ll ne=n;
    for(int i=1;i<=600;i++){
        cl[i]=cac(i);
    }
    for(int i=1;i<600;i++){
        if(ne>=cl[i] and ne<cl[i+1]){
            cout<<i;
            return 0;
        }
    }
    return 0;
}