#include <iostream>
#include <cstring>
using namespace std;
int dp[31][31];
int main(){
	int n,m,x,y;
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>m>>x>>y;
	n+=2;m+=2;x+=2;y+=2;
	dp[x-2][y-1]=0;
	dp[x-2][y+1]=0;
	dp[x+2][y-1]=0;
	dp[x+2][y+1]=0;
	dp[x+1][y-2]=0;
	dp[x+1][y+2]=0;
	dp[x-1][y-2]=0;
	dp[x-1][y+2]=0;
	dp[2][2]=0;
	dp[x][y]=0;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			
		}
	}
}
