#include <iostream>
#include <cmath>
using namespace std;
double t,x;
int cnt;
int f(int a,int b){
    if(a*a-4*b<0 or a>=0 or b<=0){
        return 0;
    }
    t=sqrt(a*a-4*b);
    x=(-a+t)/2;
}
int main(){
    for(int i=1;i<=2023;i++){
        cnt+=f(-10-i,4*i+240);
    }
    cout<<cnt<<endl;
}