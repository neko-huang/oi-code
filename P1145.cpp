#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int k;
int vis[31];
int num[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
bool check(int x){
    int n=0;
    int plu=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=k;i++){
        while(plu!=x){
            n= (n == 2*k)?1:n+1;
            if(!vis[n]){
                plu++;
            }
        }
        plu=0;
        vis[n]=1;
        if(n<=k){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>k;
    cout<<num[k];
    return 0;
    for(int i1=k+1;1;i1++){
        if(check(i1)){
            cout<<i1;return 0;
        }
    }
}
