#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    double sum,tmp,ans=0,max1,min1;
    for(int i=1;i<=n;i++){
        sum=0;min1=0xffffffffffffffff;max1=0;
        for(int j=1;j<=m;j++){
            cin>>tmp;
            max1=max(tmp,max1);
            min1=min(min1,tmp);
            sum+=tmp;
        }
        ans=max(ans,(sum-max1-min1)/double(m-2));
    }
    printf("%.2lf",ans);
    return 0;
}