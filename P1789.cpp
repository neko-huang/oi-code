#include<iostream>
using namespace std;
bool mc[105][105];
int dxt[13]={2,0,-2,0,1,1,1,0,0,0,-1,-1,-1},
    dyt[13]={0,2,0,-2,0,1,-1,1,0,-1,0,1,-1};
int dxy[25]={-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2},
    dyy[25]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
int main(){
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int x,y,o,p;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        for(int j=0;j<13;j++){
            mc[x+dxt[j]][y+dyt[j]]=1;
        }
	}
    for(int i=1;i<=k;i++){
        cin>>o>>p;
        for(int j=0;j<25;j++){
            mc[o+dxy[j]][p+dyy[j]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!mc[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}