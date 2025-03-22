#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
struct sta{
    int s[205];
};
sta first;
int cnt=1,t=1;
short won[ll(1e10+5)];
vector <sta> tu[ll(1e10+5)];
bool in[ll(1e10+5)];
ll II(sta x, int n){
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans*=x.s[i];
    }
    return ans;
}
void BFS(int n){
    queue <sta> q;
    q.push(first);
    sta tp,tmp;
    while(q.size()){
        tp=q.front();
        tmp=tp;
        q.pop();
        tu[t].push_back(tp);
        for(int i=1;i<=n;i++){
            if(tmp.s[i]==0){continue;}
            tmp.s[i]--;
            tu[t].push_back(tmp);cnt++;
            q.push(tmp);
            in[t]=1;
        }
        t++;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>first.s[i];
    }
    for(int i=1;i<=cnt;i++){
        if(!in[i]){
            won[i]=2;
            for(int p=1;p<=n;p++){
                
            }
        }
    }
}