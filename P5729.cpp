#include <iostream>
using namespace std;
bool block[31][31][31];
int main(){
    int w,x,h;
    cin>>w>>x>>h;
    int q;cin>>q;
    int x1,y1,z1,x2,y2,z2;
    while(q--){
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                for(int k=z1;k<=z2;k++){
                    block[i][j][k]=1;
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=x;j++){
            for(int k=1;k<=h;k++){
                if(!block[i][j][k]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}