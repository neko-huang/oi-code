#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef double db;
//----------------------
db x[31],y[31];
db f[30][(1<<16)-1];
//----------------------
db dist(int u,int v){
    return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}
int cnt(int n){
    int ans=0;
    while(n){
        ans+=(n%2)&&1;
        n/=2;
    }
    return ans;
}
int bt(int n,int x){
    return ((n>>(x-1))&1);
}
//---------------------
int main(){
    int n;
    cin>>n;
    memset(f,0x7f,sizeof(f));
    db ans=f[0][0];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        f[i][1<<(i-1)]=dist(0,i);
    }
    for(int i=1;i<(1<<n);i++){
    //chi le ji ge? cuo wu de
    //chi dao nage!!
        for(int j=1;j<=n;j++){//u
            if(!bt(i,j)){
                continue;
            }
            for(int k=1;k<=n;k++){//v
                if((j==k) || (!bt(i,k))){
                    continue;//bu yong zou
                }
                f[j][i]=min(f[j][i],f[k][i-(1<<(j-1))]+dist(j,k));
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=min(ans,f[i][(1<<n)-1]);
    }
    printf("%.2lf",ans);
}