#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll l,r;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int post[10]={0,-4,3,0,-1,1,1,-3,4,-1};
vector <ll> sav;
ll numstick(ll x){
    ll cnt=0;
    while(x){
        cnt+=stick[x%10];
        x/=10;
    }
    return cnt;
}
int main(){
    cin>>l>>r;
    sav.push_back(numstick(l));
    for(ll i=l+1;i<=r;i++){
        int tmp=i%10;
        if(tmp==0){
            sav.push_back(numstick(i));
        }
        else{
            sav.push_back(sav[i-l]+post[tmp]);
        }
    }
    ll len=sav.size()-1;
    ll last=0,lon=0,ans=0;
    for(ll i=0;i<=len;i++){
        if(last!=sav[i]){
            ans=max(ans,lon);
            last=sav[i];
            lon=1;
        }
        else{
            lon++;
        }
    }
    cout<<ans;
}