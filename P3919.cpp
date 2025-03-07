#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int lson,rson;
    int val;
};
const int maxn=int(1e6+5);
node tree[maxn<<5];
int ver[maxn<<2];
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
int cnt;
void change(int lver,int &nver,int l,int r,int q,int k){
    if(nver==0){
        nver=++cnt;
    }
    if(l==r){
        tree[nver].val=k;//editor
        return ;
    }
    int mid=(l+r)/2;
    if(q<=mid){
        tree[nver].rson=tree[lver].rson;
        tree[nver].lson=++cnt;
        tree[tree[nver].lson]=tree[tree[lver].lson];
        change(tree[lver].lson,tree[nver].lson,l,mid,q,k);
    }
    else{
        tree[nver].lson=tree[lver].lson;
        tree[nver].rson=++cnt;
        tree[tree[nver].rson]=tree[tree[lver].rson];
        change(tree[lver].rson,tree[nver].rson,mid+1,r,q,k);
    }
    return ;
}
int main(){
    int n=read(),m=read();
}