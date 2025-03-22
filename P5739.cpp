#include <iostream>
using namespace std;
int wow(int n){
    return n?n*wow(n-1):1;
}
int main(){
    int n;
    cin>>n;
    cout<<wow(n);
}