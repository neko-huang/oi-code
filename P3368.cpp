#include <iostream>
using namespace std;
#define debug 0
const int maxn=int(5*1e5)+5;
typedef long long ll;
int tr[maxn];
int a[maxn];
int tmp;
int n;
int lowbit(int x){
    return x&(-x);
}

#if debug==1

inline int read(){
    int rex=0,sgn=1;
    char tmp=getchar();
    while(tmp >'9' or tmp< '0'){
        if(tmp=='-'){
            sgn=-1;
        }
        tmp=getchar();
    }
    while(tmp<= '9' and tmp>='0'){
        rex=(rex<<3)+rex<<1+tmp-'0';
        tmp=getchar();
    }
    return rex*sgn;
}

#else

inline int read(){
    int n;
    scanf("%d",&n);
    return n;
}

#endif
void add(int x,int y){
    while(x<=n){
        tr[x]+=y;
        x+=lowbit(x);
    }
    return ;
}
ll search(int x){
    ll sum=0;
    sum+=tr[x];
    while(x){
        x-=lowbit(x);
        sum+=tr[x];
    }
    return sum;
}
int main(){

#ifdef _FREOPEN
    freopen("input.txt", "r", stdin);
#endif // _FREOPEN

    int m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        add(i,a[i]-a[i-1]);
    }
    int opt,x,y,k;
    while(m--){
        opt=read();
        if(opt==1){
            x=read();y=read();k=read();
            add(x,k);
            add(y+1,-k);
        }
        if(opt==2){
            x=read();
            printf("%lld\n",search(x));
        }
    }
}