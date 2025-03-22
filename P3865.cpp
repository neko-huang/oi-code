#include <iostream>
using namespace std;
#define debug 0
#if debug
inline int read(){
    int x=0,s=1;char ch=getchar();
    while(ch<'0' or ch>'9'){
        if(ch=='-'){
            s=-1;ch=getchar();
        }
    }
    while(ch>='0' and ch<='9'){
        x=x*10+(ch-'0');ch=getchar();
    }
    return x*s;
}

#else
inline int read(){
    int i;scanf("%d",&i);
    return i;
}
#endif
const int maxn=100007;
int f[maxn][18];
int a[maxn];
int l2[maxn];
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        f[i][0]=a[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
    }
    for(int i=2;i<=n;i++){
        l2[i]=l2[i/2]+1;
    }
    int l,r;
    while(m--){
        l=read();r=read();
        int i=l2[r-l+1];
        int ans=max(f[l][i],f[r-(1<<i)+1][i]);
        printf("%d\n",ans);
    }
    return 0;
}