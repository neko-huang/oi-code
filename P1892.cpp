#include <iostream>
using namespace std;
int fe[4005];
int find(int x){
    return x==fe[x]?x:fe[x]=find(fe[x]);
}
int main(){
    int n,m;
    cin>>n>>m;
    char opt;int p,q;
    for(int i=1;i<=2*n;i++){
        fe[i]=i;
    }
    while(m--){
        cin>>opt>>p>>q;
        int fep=find(p);
        int feq=find(q);
        int fep1=find(p+n);
        int feq1=find(q+n);
        if(opt == 'F'){
            fe[p]=feq;
        }
        else{
            fe[fep1]=feq;
            fe[feq1]=fep;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(fe[i]==i){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}