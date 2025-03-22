#include <iostream>
using namespace std;
const int maxn=int(1e4+5);
int brt[maxn*2+5];//1 maxn+1
int find(int x){
    return brt[x]==x?x:brt[x]=find(brt[x]);
}
void merge(int a,int b){
    brt[find(a)]=find(b);
}
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int main(){
    int n=read(),m=read();
    int p=read(),q=read();
    for(int i=1;i<=n;i++){
        brt[i]=i;
    }
    for(int i=1;i<=m;i++){ 
        brt[i+maxn]=i+maxn;
    }
    int tmp1,tmp2;
    for(int i=1;i<=p;i++){
        scanf("%d%d",&tmp1,&tmp2);
        merge(tmp1,tmp2);
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&tmp1,&tmp2);
        merge(-tmp1+maxn,-tmp2+maxn);
    }
    int man=0,woman=0;
    int tmpr=find(1);
    for(int i=1;i<=n;i++){
        if(find(i)==tmpr){
            man++;
        }
    }
    int tmpo=find(maxn+1);
    for(int i=1;i<=m;i++){
        if(find(i+maxn)==tmpo){
            woman++;
        }
    }
    cout<<min(man,woman);
}