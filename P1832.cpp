#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector <int> prime;
bool cprime[10005];
void str(int n){
    for(int i=2;i<=n;i++){
        if(!cprime[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size();j++){
            if(i*prime[j]>n){
                break;
            }
            cprime[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    return ;
}
ll f[1005];
int main(){
    ll n;cin>>n;
    str(n*10);
    f[0]=1;
    for(int j=0;prime[j]<prime.size();j++){
        for(int i=prime[j];i<=n;i++){
            f[i]+=f[i-prime[j]];
        }
    }
    cout<<f[n];
    return 0;
}