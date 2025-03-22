#include <iostream>
#include <algorithm>
using namespace std;
struct man{
    int k,s;
}peo[5003];
bool cmp(man a,man b){
    if(a.s!=b.s){
        return a.s>b.s;
    }
    return a.k<b.k;
}
int main(){
    int n,m;
    cin>>n>>m;
    m*=1.5;
    for(int i=1;i<=n;i++){
        cin>>peo[i].k>>peo[i].s;
    }
    sort(peo+1,peo+n+1,cmp);
    int ans=peo[m].s,ab=0;
    for(int i=1;peo[i].s>=ans;i++){
        ab++;
    }
    cout<<ans<<' '<<ab<<'\n';
    for(int i=1;peo[i].s>=ans;i++){
        cout<<peo[i].k<<' '<<peo[i].s<<'\n';
    }
    return 0;
}