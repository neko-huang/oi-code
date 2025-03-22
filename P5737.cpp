#include <iostream>
#include <vector>
using namespace std;
vector <int> rcd;
bool isyear(int x){
    if(x%4==0 and x%100!=0){
        return 1;
    }
    if(x%400==0){
        return 1;
    }
    return 0;
}
int main(){
    int x,y;
    cin>>x>>y;
    for(int i=x;i<=y;i++){
        if(isyear(i)){
            rcd.push_back(i);
        }
    }
    cout<<rcd.size()<<'\n';
    for(int i=0;i<rcd.size();i++){
        cout<<rcd[i]<<' ';
    }
}