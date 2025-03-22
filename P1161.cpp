#include <iostream>
using namespace std;
bool lamp[2000005];
int main(){
    int n;
    cin>>n;
    double a;int t;
    for(int j=1;j<=n;j++){
        cin>>a>>t;
        for(double i=1;i<=t;i+=1.0){
            lamp[int(a*i)]=lamp[int(a*i)]?0:1;
        }
    }
    for(int i=1;1;i++){
        if(lamp[i]){
            cout<<i;
            return 0;
        }
    }
    return 0;
}