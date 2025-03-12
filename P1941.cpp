#include <iostream>
using namespace std;
struct guan{
	int p,l,h;
	
};
bool cmp(guan a,guan b){
	return a.p<b.p;
}
guan dao[10005];
int dx[10005];
int dy[10005];
int dp[]
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>dx[i]>>dy[i];
	}
	for(int i=1;i<=k;i++){
		cin>>dao[i].p>>dao[i].l>>dao[i].h;
	}
	sort(dao+1,dao+k+1,cmp);
	for(int i=1;i<=n;i++){
		
	}
}
