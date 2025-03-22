#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
    ll a,b;
    cin>>a>>b;
    double ans=pow(a,b);
    if(ans>1e9){
        cout<<"-1";
    }
    else{
        cout<<ll(ans);
    }
}