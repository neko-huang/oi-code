#include<iostream>
using namespace std;
int n;
char tree[114514];
bool c[114514];
int pow2(int x){
    int mo=1;
    for(int i=1;i<=x;i++){
        mo*=2;
    }
    return mo;
}
char FBI1(bool a){
    return a==1?'I':'B';
}
char FBI2(char a,char b){//0 b 1 i 01f
    if(a=='B' and b=='B'){return 'B';}
    else if(a=='I' and b=='I'){return 'I';}
    else {return 'F';}
}
void out(int n){
    if(tree[n]=='*')return ;
    out(2*n);
    out(2*n+1);
    cout<<tree[n];
}
int main(){
    for(int i=0;i<114514;i++){
        tree[i]='*';
    }
    cin>>n;
    //cin>>c;
    int gnt=pow2(n);
    for(int i=1;i<=gnt;i++){
        scanf("%1d",&c[i]);
        tree[gnt+i-1]=FBI1(c[i]);
    }
    for(int i=2*gnt-2;i>=2;i-=2){
        tree[i/2]=FBI2(tree[i],tree[i+1]);
    }
    out(1);
}