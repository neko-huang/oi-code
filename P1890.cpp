#include <iostream>
using namespace std;
struct node{
    int l,r;
    int ngcd;
};
node tree[4005];
int a[1023];
inline int read(){
    int n;
    scanf("%d",&n);
    return n;
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void build_tree(int bl,int br,int now){
    tree[now].l=bl;
    tree[now].r=br;
    if(bl==br){
        tree[now].ngcd=a[bl];
        return ;
    }
    int mid=(tree[now].l+tree[now].r)/2;
    build_tree(bl,mid,now*2);
    build_tree(mid+1,br,now*2+1);
    tree[now].ngcd=gcd(tree[now*2].ngcd,tree[now*2+1].ngcd);
    return ;
}
int query(int ql,int qr,int now){
    if(tree[now].l>=ql and tree[now].r<=qr){
        return tree[now].ngcd;
    }
    int mid=(tree[now].l+tree[now].r)/2;
    int ans=0;
    if(ql<=mid){
        ans=gcd(query(ql,qr,now*2),ans);
    }
    if(qr>mid){
        ans=gcd(query(ql,qr,now*2+1),ans);
    }
    return ans;
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build_tree(1,n,1);
    int al,ar;
    for(int i=1;i<=m;i++){  
        al=read();ar=read();
        printf("%d\n",query(al,ar,1));
    }
    return 0;
}