#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=int(1e5+5);
vector <int> a;
vector <int> lite;
vector <int> solve;
struct node{
    int l,r;
    int sum;
};
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
void out(int n){
    printf("%d\n",n);
    return ;
}
node tree[maxn*4];
void upd(int x){
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
void build(int x,int bl,int br){
    tree[x].l=bl;
    tree[x].r=br;
    tree[x].sum=0;
    if(bl==br){
        return ;
    }
    int mid=(bl+br)/2;
    build(x*2,bl,mid);
    build(x*2+1,mid+1,br);
    upd(x);
    return ;
}
void insert(int x,int n){
    if(tree[x].l==tree[x].r){
        tree[x].sum++;
        return ;
    }
    int mid=(tree[x].l+tree[x].r)/2;
    if(n<=mid){
        insert(x*2,n);
    }
    else{
        insert(x*2+1,n);
    }
    upd(x);
    return ;
}
int query_mid(int x,int n){
    if(tree[x].l==tree[x].r){
        return lite[tree[x].l];
    }
    if(n>tree[x*2].sum){
        return query_mid(x*2+1,n-tree[x*2].sum);
    }
    else{
        return query_mid(x*2,n);
    }
}
int main(){
    int n=read();int tmp;
    a.push_back(0);
    lite.push_back(0);
    for(int i=1;i<=n;i++){
        tmp=read();
        a.push_back(tmp);
        lite.push_back(tmp);
    }
    int m=read();
    char opt[4];
    for(int i=1;i<=m;i++){
        scanf("%s",opt);
        if(opt[0]=='a'){
            tmp=read();
            a.push_back(tmp);
            lite.push_back(tmp);
        }
        else{
            solve.push_back(n+i);
        }
    }
    int itt=0;
    sort(lite.begin()+1,lite.end());
    lite.erase(unique(lite.begin(),lite.end()),lite.end());
    for(int i=1;i<a.size();i++){
        a[i]=lower_bound(lite.begin(),lite.end(),a[i])-lite.begin();
    }
    build(1,1,lite.size());
    for(int i=1;i<a.size();i++){
        insert(1,a[i]);
        while(solve[itt]==i+itt+1){
            if(i%2==1){
                out(query_mid(1,(i+1)/2));
            }
            else{
                out(min(query_mid(1,(i+1)/2),query_mid(1,(i+1)/2+1)));
            }
            itt++;
        }
    }
    return 0;
}