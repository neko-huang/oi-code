#include <iostream>
using namespace std;
int a[127];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=i-1;j>=1;j--){
            if(a[j]<a[i]){
                cnt++;
            }
        }
        cout<<cnt<<' ';
    }
    return 0;
}