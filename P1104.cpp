//AC
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct peo{
    string s;
    int y,m,d,st;
};
peo lis[127];
bool cmp(peo a,peo b){
    if(a.y!=b.y){
        return a.y<b.y;
    }
    if(a.m!=b.m){
        return a.m<b.m;
    }
    if(a.d!=b.d){
        return a.d<b.d;
    }
    return a.st>b.st;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lis[i].s>>lis[i].y>>lis[i].m>>lis[i].d;
        lis[i].st=i;
    }
    sort(lis+1,lis+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<lis[i].s<<'\n';
    }
}