#include <iostream>
using namespace std;int k[63][63];
int main(){
    int n;
    int backx,backy;
    cin>>n;
    for(int i=1;i<=n*n;i++){
            if(i==1){
                k[1][n/2+1]=i;
                backx=1;backy=n/2+1;
            }
            else if(backx==1 and backy!=n){
                k[n][backy+1]=i;
                backx=n;backy+=1;
            }
            else if(backx!=1 and backy==n){
                k[backx-1][1]=i;
                backx-=1;backy=1;
            }
            else if(backx==1 and backy==n){
                k[backx+1][backy]=i;
                backx+=1;
            }
            else if(backx!=1 and backy!=n){
                if(!k[backx-1][backy+1]){
                    k[backx-1][backy+1]=i;
                    backx-=1;backy+=1;
                }
                else{
                    k[backx+1][backy]=i;
                    backx+=1;
                }
            }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<k[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}