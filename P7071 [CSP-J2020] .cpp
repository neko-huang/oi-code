#include <iostream>
#include <vector>
using namespace std;
int power[40];
vector <int> ans;
int main(){
    ios::sync_with_stdio(0);
            int n;
    cin>>n;
    if(n==0 or n%2==1){
        cout<<"-1";return 0;
    }
    power[1]=2;
    for(int i=2;i<=30;i++){
        power[i]=power[i-1]*2;
    }
    int tmp=n,i=30;
    while(tmp>0 and i>0){
        if(tmp>=power[i]){
            ans.push_back(power[i]);tmp-=power[i];
        }
        i--;
    }
    if(tmp==1){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<=ans.size()-1;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}