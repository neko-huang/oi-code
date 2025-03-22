#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    return a+b>b+a;
}
string lis[100];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lis[i];
    }
    sort(lis+1,lis+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<lis[i];
    }
}