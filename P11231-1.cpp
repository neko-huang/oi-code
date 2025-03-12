#include <iostream>
#include <algorithm>
using namespace std;
int r[100005];
int buc[100005];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		buc[r[i]]++;
	}
	int ans=0;
	for(int i=1;i<=100000;i++){
		ans=max(ans,buc[i]);
	}
	cout<<ans; 
	return 0;
} 
