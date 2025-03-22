#include <iostream>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    int cnt=0;
    bool flag=0;
    while(cnt<n*n){
        cin>>tmp;
        for(int i=1;i<=tmp;i++){
            cout<<flag;
            if((cnt+i)%n==0){
                cout<<'\n';
            }
        }
        cnt+=tmp;
        flag=flag?0:1;
    }
    return 0;
}