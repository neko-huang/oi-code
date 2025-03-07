#include <iostream>
using namespace std;
const int maxn=100005;
int tr[maxn];
int a[maxn];
int n;
int lowbit (int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=n){
        tr[x]+=y;
        x+=lowbit(x);
    }
    return ;
}
int search(int x){
    int ans=0;
    while(x){
        ans+=tr[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans1=n;
    while(a[ans1]>=a[ans1-1]){
        add(a[ans1--],1);
    }
    add(a[ans1--],1);
    printf("%d\n",ans1);
    for(int i=1;i<=ans1;i++){
        printf("%d ",search(a[i])+ans1-i);
        add(a[i],1);
    }
    return 0;
}