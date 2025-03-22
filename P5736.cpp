#include <iostream>
#include <vector>
using namespace std;
bool vis[100008];
vector <int> prime;
int main(){
    vis[0]=vis[1]=1;
    for(int i=2;i<=100000;i++){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size() and i*prime[j]<=100000;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(!vis[tmp]){
            cout<<tmp<<' ';
        }
    }
    return 0;
}