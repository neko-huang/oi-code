#include <iostream>
#include <algorithm>
using namespace std;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int poke[127];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n=read();
    int sum=0;
    for(int i=1;i<=n;i++){
        poke[i]=read();
        sum+=poke[i];
    }
    sum/=n;
    int ans=0;
    //sort(poke+1,poke+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(poke[i]!=sum){
            poke[i+1]+=(poke[i]-sum);
            poke[i]=sum;
            ans++;
        }
    }
    cout<<ans;
}