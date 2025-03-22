#include <iostream>
using namespace std;
int main(){
    int n,l,r;
    cin>>n>>l>>r;
    if(r/n-l/n>0){
        cout<<n-1;return 0;
    }
    else{
        cout<<r%n;
    }
    return 0;
}