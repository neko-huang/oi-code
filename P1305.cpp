#include <iostream>
using namespace std;
char tree[11451];int n;
struct root{
    char le,mi,ri;
}tr[30];
int cs(char x){
    for(int i=1;i<=n;i++){
        if(tr[i].mi==x){
            return i;
        }
    }
    return 0;
}
void out(int n){
    if(tree[n]=='*')return ;
    cout<<tree[n];
    out(2*n);
    out(2*n+1);
}
int main(){
    for(int i=0;i<11451;i++){
        tree[i]='*';
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tr[i].mi>>tr[i].le>>tr[i].ri;
    }
    tree[1]=tr[1].mi;//tree[2]=tr[1].le;tree[3]=tr[1].ri;
    for(int i=1;i<=11450;i++){
        if(tree[i]=='*'){continue;}
        int tmp=cs(tree[i]);
        if(tmp){
            tree[i*2]=tr[tmp].le;
            tree[i*2+1]=tr[tmp].ri;
        }
    }
    out(1);
}