#include <iostream>
using namespace std;
bool dp[2047];
int a[7];
int g[7]={0,1,2,3,5,10,20};
int main(){
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(int f=1;f<=6;f++){
        for(int i=1;i<=a[f];i++){
            for(int j=1000;j>=0;j--){
                if(dp[j]){
                    dp[j+i*g[f]]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=1000;i++){
        ans+=dp[i];
    }
    cout<<"Total="<<ans;
}