#include <iostream>
using namespace std;
bool tree[4*10000005],flag;
int ans;
void upd(int x){
    tree[x]=(tree[x*2]&&tree[x*2+1]);
    return ;
}
void add(int x,int al,int ar,int tl,int tr){
    if(tree[x]){
        return ;
    }
    if(al<=tl and tr<=ar){
        tree[x]=1;
        flag=1;
        return ;
    }
    int mid=(tl+tr)/2;
    if(al<=mid){
        add(x*2,al,ar,tl,mid);
    }
    if(ar>mid){
        add(x*2+1,al,ar,mid+1,tr);
    }
    upd(x);
    return ;
}
int a[1023],b[1023];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=m;i>=1;i--){
        flag=0;
        add(1,a[i],b[i],1,n);
        if(flag){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}