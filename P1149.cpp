#include <iostream>
using namespace std;
int ans=0;
int stick[10]={
    6,2,5,5,4,5,6,3,7,6
};
int num[12000];
int buc(int n){
    int ret=0;
    while(n){   
        ret+=stick[n%10];
        n/=10;
    }
    return ret;
}
int main(){
    int n;
    cin>>n;
    num[0]=6;
    for(int i=1;i<=10000;i++){
        num[i]=buc(i);
    }
    for(int i=0;i<=4999;i++){
        for(int j=0;j<=4999;j++){
            if(num[i]+num[j]+num[i+j]+4==n){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}