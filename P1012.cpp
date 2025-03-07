#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector <int> a,vector<int> b){
    if(a.size()!=b.size())return a.size()>b.size();
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[a.size()-i]!=b[b.size()-i])return a[a.size()-i]>b[b.size()-i];
    }
}
vector <int> num[31];
int main(){
    int n;int tmp;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        while(tmp){
            num[i].push_back(tmp%10);
            tmp/=10;
        }
    }
    sort(num+1,num+1+n,cmp);
    for(int i=1;i<=n;i++){
        for(int j=num[i].size()-1;j>=0;j--){
            cout<<num[i][j];
        }
    }
    return 0;
}