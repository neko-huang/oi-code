#include <iostream>
using namespace std;
int ask[7][31];
int s[5];
int lbrain,rbrain;
int ans;
int mans;
void dfs(int l,int n){
    if(l>s[n]){
        ans=min(ans,max(lbrain,rbrain));
        return ;
    }
    lbrain+=ask[n][l];
    dfs(l+1,n);
    lbrain-=ask[n][l];
    rbrain+=ask[n][l];
    dfs(l+1,n);
    rbrain-=ask[n][l];
    return ;
}
int main(){
    for(int i=1;i<=4;i++){
        cin>>s[i];
    }
    for(int i1=1;i1<=4;i1++){
        for(int j=1;j<=s[i1];j++){
            cin>>ask[i1][j];
        }
        lbrain=0;rbrain=0;
        ans=0x3f3f3f3f;
        dfs(1,i1);
        mans+=ans;
    }
    cout<<mans;
    return 0;
}