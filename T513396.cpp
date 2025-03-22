#include <iostream>
using namespace std;
//#define ll long long
int block[50000010],igt;//block[i]=sq(n-i*2+2)-sq(n-i*2);
void buildmelon(int n){
    igt=(n-1)/2+1;
    for(int i=1;i<igt;i++){
        block[i]=4*(n-i*2+1);
    } 
    block[igt]=n%2?1:4;
    return ;
}
int eatmelon(int x){ 
    int ans=0,i;
    for(i=igt;i>=1 and x>block[i];i--){
        ans+=i*block[i];
        x-=block[i];
    }
    //i--;
    ans+=x*i;
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    block[0]=0x3f3f3f3f;
    buildmelon(n);
    cout<<eatmelon(m);
    return 0;
}
