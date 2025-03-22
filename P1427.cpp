#include <iostream>
using namespace std;
int a[127];
int main(){
    int i=1;
    for(i=1;1;i++){
        cin>>a[i];
        if(!a[i]){
            break;
        }
    }
    for(int j=i-1;j>0;j--){
        cout<<a[j]<<' ';
    }
    return 0;
}