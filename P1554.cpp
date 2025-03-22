#include <iostream>
using namespace std;
int buc[15];
void dep(int n){
    while(n){
        buc[n%10]++;
        n/=10;
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        dep(i);
    }
    for(int i=0;i<=9;i++){
        cout<<buc[i]<<' ';
    }
}