#include <iostream>
using namespace std;
struct score{
    int lvl,s,w;
};
bool cmp(score a,score b){
    return a.s==b.s?a.lvl<b.lvl:a.s>b.s;
}
score player[200048];
score tmp[200048];
void merge(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    merge(l,mid); 
    merge(mid+1,r);
    int i=l,j=mid+1,tot=1;
    while(i<=mid and j<=r){
        if(cmp(player[i],player[j])){
            tmp[tot++]=player[i++];
        }
        else{
            tmp[tot++]=player[j++];
        }
    }
    while(i<=mid){
        tmp[tot++]=player[i++];
    }
    while(j<=r){
        tmp[tot++]=player[j++];
    }
    for(int i=1;i<=tot-1;i++){
        player[l++]=tmp[i];
    }
}
int main(){
    int n,r,q;
    cin>>n>>r>>q;
    for(int i=1;i<=2*n;i++){
        scanf("%d",&player[i].s);
        player[i].lvl=i;
    }
    for(int i=1;i<=2*n;i++){
        scanf("%d",&player[i].w);
    }
    for(int i=1;i<=r;i++){
        merge(1,2*n);
        for(int p=1;p<=2*n;p+=2){
            if(player[p].w<player[p+1].w){
                player[p+1].s++;
            }
            else{
                player[p].s++;
            }
        }
    }
    merge(1,2*n);
    cout<<player[q].lvl;
}