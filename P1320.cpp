#include <iostream>
#include <cmath>
using namespace std;
char a;bool flag;
int n,ans[1000001],now=1;
int main(){
    while(cin>>a){
        if(a=='\n'){
            continue;
        }
        n++;
        if(a-'0'==flag){
            ans[now]++;
        }
        else{
            ans[++now]++;
            flag=a=='1'?1:0;
        }
    }
    cout<<sqrt(n)<<' ';
    for(int i=1;i<=now; i++){
        cout<<ans[i]<<' ';
    }
}