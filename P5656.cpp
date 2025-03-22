#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(int x,int y){
    return y?gcd(y,x%y):1;
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;return ;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c%gcd(a,b)){
        cout<<"-1";
        return 0;
    }
    
}