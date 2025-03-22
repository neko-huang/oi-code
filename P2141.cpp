#include <iostream>
#include <algorithm>
using namespace std;
int list[127];
int cnt[20005];
int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>list[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cnt[list[i]+list[j]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[list[i]]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}