#include <iostream>
using namespace std;
const int maxn=180005;
struct node{
    int l=0,r=0;
    int maxc=0,minc=0x3f3f3f3f;
}cow[maxn*4];
int h[maxn];
void upd(int x){
    cow[x].maxc=max(cow[x*2].maxc,cow[x*2+1].maxc);
    cow[x].minc=min(cow[x*2].minc,cow[x*2+1].minc);
}
void buildtree(int x,int bl ,int br){
    cow[x].l=bl;
    cow[x].r=br;
    if(bl==br){
        cow[x].maxc=h[bl];
        cow[x].minc=h[bl];
        return;
    }
    int mid=(bl+br)/2;
    buildtree(x*2,bl,mid);
    buildtree(x*2+1,mid+1,br);
    upd(x);
}
int maxquery(int x,int ql,int qr){
    if(cow[x].r<ql or cow[x].l>qr){
        return 0;
    }
    if(cow[x].l>=ql and cow[x].r<=qr){
        return cow[x].maxc;
    }
    int mid=(cow[x].l+cow[x].r)/2;
    return max(maxquery(x*2,ql,mid),maxquery(x*2+1,mid + 1,qr));
}
int minquery(int x,int ql,int qr){
    if(cow[x].r<ql or cow[x].l>qr){
        return 0x3f3f3f3f;
    }
    if(cow[x].l>=ql and cow[x].r<=qr){
        return cow[x].minc;
    }
    int mid=(cow[x].l+cow[x].r)/2;
    if (mid>=ql)
    {
        
    }
    
    return min(minquery(x*2,ql,mid),minquery(x*2+1,mid + 1,qr));
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    buildtree(1,1,n);
    int a,b;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",maxquery(1,a,b)-minquery(1,a,b));
    }
    return 0;
}
