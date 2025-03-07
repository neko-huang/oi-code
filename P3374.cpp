#include <iostream>
using namespace std;
#define debug 0
const int maxn=int(5*1e5)+5;
int tr[maxn];
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
int search(int x){
    int sum=0;
    sum+=tr[x];
    while(x){
        x-=lowbit(x);
        sum+=tr[x];
    }
    return sum;
}
int main(){
    int m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        tmp=read();
        add(i,tmp);
    }
    int opt,x,y;
    while(m--){
        opt=read();x=read();y=read();
        if(opt==1){
            add(x,y);
        }
        if(opt==2){
            cout<<search(y)-search(x-1)<<endl;
        }
    }
}