#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=int(2*1e5+5);
struct node{
    int lson,rson;
    int num;
};
node tree[maxn<<5];
int ver[maxn<<2];
int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c>'9' or c<'0'){
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
vector <int> a;
vector <int> lite;
int cnt;
void upd(int x){
    tree[x].num=tree[tree[x].lson].num+tree[tree[x].rson].num;
    return ;
}
void change(int lver,int &nver,int l,int r,int q){
    if(nver==0){
        nver=++cnt;
    }
    if(l==r){
        tree[nver].num++;
        return ;
    }
    int mid=(l+r)/2;
    if(q<=mid){
        tree[nver].rson=tree[lver].rson;
        tree[nver].lson=++cnt;
        tree[tree[nver].lson]=tree[tree[lver].lson];
        change(tree[lver].lson,tree[nver].lson,l,mid,q);
    }
    else{
        tree[nver].lson=tree[lver].lson;
        tree[nver].rson=++cnt;
        tree[tree[nver].rson]=tree[tree[lver].rson];
        change(tree[lver].rson,tree[nver].rson,mid+1,r,q);
    }
    upd(nver);
    return ;
}
int query(int ver1,int ver2,int ql,int qr,int k){
    if(ql==qr){
        return ql;
    }
    int mid=(ql+qr)/2;
    int tmp=tree[tree[ver2].lson].num-tree[tree[ver1].lson].num;
    if(k<=tmp){
        return query(tree[ver1].lson,tree[ver2].lson,ql,mid,k);
    }
    else{
        return query(tree[ver1].rson,tree[ver2].rson,mid+1,qr,k-tmp);
    }
}
int main(){
    int n=read();
    int m=read();
    a.resize(n+1);
    lite.resize(n+1);
    for(int i=1;i<=n;i++){
        a[i]=read();
        lite[i]=a[i];
    }
    sort(lite.begin()+1,lite.begin()+1+n);
    lite.erase(unique(lite.begin()+1,lite.begin()+1+n),lite.end());
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(lite.begin()+1,lite.end(),a[i])-lite.begin();
    }
    for(int i=1;i<=n;i++){
        change(ver[i-1],ver[i],1,lite.size()-1,a[i]);
    }
    int l,r,k;
    while(m--){
        l=read(),r=read(),k=read();
        printf("%d\n",lite[query(ver[l-1],ver[r],1,lite.size()-1,k)]);
    }
    return 0;
}