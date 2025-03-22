#include <iostream>
using namespace std;
int c[1023],m[1023],e[1023];
int abs(int n){
    return n>0?n:-n;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>m[i]>>e[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(c[j]-c[i])<=5 and abs(m[j]-m[i])<=5 and abs(e[j]-e[i])<=5){
                if(abs(c[j]+m[j]+e[j]-c[i]-m[i]-e[i])<=10){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}