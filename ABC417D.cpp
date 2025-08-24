#include<bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n;                      //前i件物品导致心情下降，下降了多少
int p[maxn],a[maxn],b[maxn],s[maxn];
int f[maxn][1005];
//f[i][j]表示从第i轮开始，第i轮的心情为j，最终的心情
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>a[i]>>b[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=0;i<=1000;i++)
		f[n+1][i]=i;//超过n轮心情固定
	for(int i=n;i>=1;i--){
		for(int j=0;j<=1000;j++){
			if(p[i]>=j)
				f[i][j]=f[i+1][j+a[i]];
			else
				f[i][j]=f[i+1][max(0LL,j-b[i])];
		}
	}
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		if(x<=1000) cout<<f[1][x]<<'\n';
		else{
			int l=1,r=n,pos=n+1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x-s[mid-1]<=1000){
					pos=mid;
					r=mid-1;
				}
				else
					l=mid+1;
			}
			if(pos>n)//n轮后心情仍然超过1000
				cout<<x-s[n]<<'\n';//
			else//从pos轮开始，初始心情减去pos-1轮的b[]
				cout<<f[pos][x-s[pos-1]]<<'\n';
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define maxn 10005
using namespace std;
int n;                      //前i件物品导致心情下降，下降了多少
int p[maxn],a[maxn],b[maxn],s[maxn];
int f[maxn][1005];
//f[i][j]表示从第i轮开始，第i轮的心情为j，最终的心情
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>a[i]>>b[i];
		s[i]=s[i-1]+b[i];
	}
	for(int i=0;i<=1000;i++)
		f[n+1][i]=i;//超过n轮心情固定
	for(int i=n;i>=1;i--){
		for(int j=0;j<=1000;j++){
			if(p[i]>=j)
				f[i][j]=f[i+1][j+a[i]];
			else
				f[i][j]=f[i+1][max(0LL,j-b[i])];
		}
	}
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		if(x<=1000) cout<<f[1][x]<<'\n';
		else{
			int l=1,r=n,pos=n+1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(x-s[mid-1]<=1000){
					pos=mid;
					r=mid-1;
				}
				else
					l=mid+1;
			}
			if(pos>n)//n轮后心情仍然超过1000
				cout<<x-s[n]<<'\n';//
			else//从pos轮开始，初始心情减去pos-1轮的b[]
				cout<<f[pos][x-s[pos-1]]<<'\n';
		}
	}
	return 0;
}
