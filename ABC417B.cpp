#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=int(105);
int a[maxn],b[maxn];
int main(){
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		cin>>b[j];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==b[i]){
				a[j]=-1;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			cout<<a[i]<<' ';
		}
	}
	
	return 0;
}