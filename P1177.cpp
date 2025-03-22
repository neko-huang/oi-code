#include <iostream>
using namespace std;
int lis[100005];
int tmp[100005];
void merge(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    merge(l,mid); 
    merge(mid+1,r);
    int i=l,j=mid+1,tot=1;
    while(i<=mid and j<=r){
        if(lis[i]<lis[j]){
            tmp[tot++]=lis[i++];
        }
        else{
            tmp[tot++]=lis[j++];
        }
    }
    while(i<=mid){
        tmp[tot++]=lis[i++];
    }
    while(j<=r){
        tmp[tot++]=lis[j++];
    }
    for(int i=1;i<=tot-1;i++){
        lis[l++]=tmp[i];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&lis[i]);
    }
    merge(1,n);
    for(int i=1;i<=n;i++){
        printf("%d ",lis[i]);
    }
    return 0;
}