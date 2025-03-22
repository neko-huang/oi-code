#include <iostream>
using namespace std;
int l,n,m;
int d[50005];
namespace g{
    bool o(int x){
        int i=0,now=0,rock=0;
        while(now<n+1){
            now++;
            if(d[now]-d[i]>=x){
                i=now;
            }
            else{
                rock++;
            }
        }
        return rock<=m;
    }
}
int main(){
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    d[n+1]=l;
    int left=1,right=int(1e9+5),mid,lans;
    while(left<=right){
        mid=(left+right)/2;
        if(g::o(mid)){
            lans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<lans;
}