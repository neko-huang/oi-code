#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int f[55][500005];
int blocks[55];
int max(int a,int b,int c){
    int m=a;
    if(m<b){m=b;}
    if(m<c){m=c;}
    return m;
}
int max(int a,int b,int c,int d){
    int m=a;
    if(m<b){m=b;}
    if(m<c){m=c;}
    if(m<d){m=d;}
    return m;
}
int main(){
    int n,m=0;
    cin>>n;
    memset(f,-0x3f3f3f3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        cin>>blocks[i];
        m+=blocks[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(blocks[i]>j){
                //f[i][j]=max(f[i-1][j],f[i-1][j+blocks[i]],f[i-1][blocks[i]-j]);
                f[i][j]=max(f[i][j],f[i-1][j],f[i-1][j+blocks[i]],f[i-1][blocks[i]-j]+j);
            }
            else{
                //f[i][j]=max(f[i-1][j],f[i-1][j+blocks[i]],f[i-1][j-blocks[i]]+blocks[i]);
                f[i][j]=max(f[i][j],f[i-1][j],f[i-1][j+blocks[i]],f[i-1][j-blocks[i]]+blocks[i]);
            }
        }
    }
    if(f[n][0]>0){
        cout<<f[n][0];
    }
    else{
        cout<<"-1";
    }
    return 0;
}