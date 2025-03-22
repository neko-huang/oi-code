#include <iostream>
using namespace std;
int ans[15];
int buy[15];
int win[15];
bool check(int n){
    for(int i=1;i<=7;i++){
        if(ans[i]==n){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=7;i++){
        cin>>ans[i];
    }
    int cnt;
    while(n--){
        cnt=0;
        for(int i=1;i<=7;i++){
            cin>>buy[i];
            if(check(buy[i])){
                cnt++;
            }
        }
        win[7-cnt+1]++;
    }
    for(int i=1;i<=7;i++){
        cout<<win[i]<<' ';
    }
}