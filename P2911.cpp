#include <iostream>
using namespace std;
int cnt[127];
int main(){
    int s[7];
    for(int i=1;i<=3;i++){
        cin>>s[i];
    }
    for(int i=1;i<=s[1];i++){
        for(int j=1;j<=s[2];j++){
            for(int k=1;k<=s[3];k++){
                cnt[i+j+k]++;
            }
        }
    }
    int ans=1;
    for(int i=2;i<=s[1]+s[2]+s[3];i++){
        if(cnt[ans]<cnt[i]){
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}