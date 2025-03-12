#include <iostream>
using namespace std;
const int maxn=int(1e5+5);
void pushdown(int x);
double query(int x,int ql,int qr);
struct node{
    int l,r;
    double sum,fot;
    double lzt;
};
node tree[maxn<<2];signed
int a[maxn];
int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c>='0' and c<='9'){
        igt=igt*10+c-'0';
        c=getchar();
    }
    return igt*sgn;
}
void upd(int x){
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    tree[x].fot=tree[x*2].fot+tree[x*2+1].fot;
    return ;
}
void build(int x,int bl,int br){
    tree[x].l=bl;
    tree[x].r=br;
    if(bl==br){
        tree[x].sum=double(a[bl]);
        tree[x].fot=double(a[bl]*a[bl]);
        return ;
    }
    int mid=(bl+br)/2;
    build(x*2,bl,mid);
    build(x*2+1,mid+1,br);
    upd(x);
    return ;
}
void pushdown(int x){
    if(tree[x].lzt){
        tree[x*2].lzt+=tree[x].lzt;
        tree[x*2+1].lzt+=tree[x].lzt;
        tree[x*2].sum+=tree[x].lzt*(tree[x*2].r-tree[x*2].l+1);
        tree[x*2+1].sum+=tree[x].lzt*(tree[x*2+1].r-tree[x*2+1].l+1);
        tree[x*2].fot+=tree[x].lzt*tree[x].lzt*(tree[x*2].r-tree[x*2].l+1)+2*query(1,tree[x*2].l,tree[x*2].r)*tree[x].lzt;
        tree[x*2+1].fot+=tree[x].lzt*tree[x].lzt*(tree[x*2+1].r-tree[x*2+1].l+1)+2*query(1,tree[x*2+1].l,tree[x*2+1].r)*tree[x].lzt;
        tree[x].lzt=0;
    }
    return ;
}
void add(int x,int al,int ar,int n){
    if(al<=tree[x].l and tree[x].r<=ar){
        tree[x].sum+=(double)(tree[x].r-tree[x].l+1)*n;
        tree[x].fot+=(double)(tree[x].lzt*tree[x].lzt*(tree[x].r-tree[x].l+1)+2*query(1,tree[x].l,tree[x].r)*tree[x].lzt);
        tree[x].lzt+=(double)n;
        return ;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    pushdown(x);
    if(mid>=al){
        add(x*2,al,ar,n);
    }
    if(mid<ar){
        add(x*2+1,al,ar,n);
    }
    upd(x);
    return ;
}
double query(int x,int ql,int qr){
    if(ql<=tree[x].l and tree[x].r<=qr){
        return tree[x].sum;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    pushdown(x);
    double ret=0;
    if(mid>=ql){
        ret+=query(x*2,ql,qr);
    }
    if(mid<qr){
        ret+=query(x*2+1,ql,qr);
    }
    return ret;
}
double query_fot(int x,int ql,int qr){
    if(ql<=tree[x].l and tree[x].r<=qr){
        return tree[x].fot;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    pushdown(x);
    double ret=0;
    if(mid>=ql){
        ret+=query_fot(x*2,ql,qr);
    }
    if(mid<qr){
        ret+=query_fot(x*2+1,ql,qr);
    }
    return ret;
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    int opt;
    int x,y,k;
    while(m--){
        opt=read();
        if(opt==1){
            x=read();y=read();k=read();
            add(1,x,y,k);
        }
        else if(opt==2){
            x=read();y=read();
            double tmpu=query(1,x,y);
            double tmpd=double(y-x+1);
            printf("%.4lf\n",tmpu/tmpd);
        }
        else{
            x=read();y=read();
            double tmpu=double(query(1,x,y));
            double tmpd=double(y-x+1);
            double tmpm=(tmpu/tmpd)*(tmpu/tmpd);
            double tmpf=double(query_fot(1,x,y))/tmpd;
            printf("%.4lf\n",tmpf-tmpm);
        }
    }
    return 0;
}