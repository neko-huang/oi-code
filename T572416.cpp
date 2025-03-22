#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
vector <int> dan;
vector <int> shu;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n=read(),k=read();
    while(n--){
        int tmp=read();
        if(tmp%2==1){
            dan.push_back(tmp);
        }
        else{
            shu.push_back(tmp);
        }
    }
    sort(dan.begin(),dan.end(),cmp);
    sort(shu.begin(),shu.end(),cmp);
    long long danans=0,shuans=0;
    if(k>dan.size() and k>shu.size()){
        printf("0");
        return 0;
    }
    if(k<=dan.size()){
        for(int i=0;i<k;i++){
            danans+=dan[i];
        }
    }
    if(k<=shu.size()){
        for(int i=0;i<k;i++){
            shuans+=shu[i];
        }
    }
    printf("%lld",max(danans,shuans));
    return 0;
}