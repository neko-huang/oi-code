#include <iostream>
#include <algorithm>
using namespace std;
int sc[10240];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sc[i];
    }
    sort(sc+1,sc+n+1);
    for(int i=1;i<=n;i++){
        cout<<sc[i]<<' ';
    }
    int i=1,j=n,ans=0;
    while(i<=j){
        int mid=(i+j)>>1;
        if(sc[mid]<60){
            i=mid+1;ans=sc[mid];
        }
        else{
            j=mid-1;
        }
    }
    if(ans==0){cout<<"\n-1";return 0;}
    cout<<'\n'<<ans;
    return 0;
}