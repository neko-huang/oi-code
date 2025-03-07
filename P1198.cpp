#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll D,t=0;
struct node{
    int l,r;
    int max;
};
node sgntree[800005];
int lentree;
inline ll read(){
    ll n;
    scanf("%lld",&n);
    return n;
}

int main(){
    ll m;
    m=read();D=read();
    char tmp[100];
    char opt;int n=0;lentree=1;
    while(m--){
        cin.getline(tmp,100);
        opt=tmp[0];
        for(int i=3;tmp[i+1]!='\0';i++){
            n=n<<3+n<<1+tmp[i]-'0';
        }
        if(opt=='A'){
            
        }
    }
}