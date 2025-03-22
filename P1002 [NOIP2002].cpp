#include <iostream>
using namespace std;
int dx[10]={0,1,2,-1,-2,1,2,-1,-2};
int dy[10]={0,2,1,2,1,-2,-1,-2,-1};
int dp[31][31];
bool horse[31][31];
int main(){
    int bx,by,mx,my;
    cin>>bx>>by>>mx>>my;
    for(int i=1;i<=8;i++){
        if(mx+dx[i]<0 or my+dy[i]<0)(
            continue;
        )
        horse[mx+dx[i]][my+dy[i]]=1;
    }
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){

        }
    }
}