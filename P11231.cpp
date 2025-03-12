#include <iostream>
#include <algorithm>
using namespace std;
int r[100005];
int buc[100005];
int cand;
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		buc[r[i]]++;
	}
	int l=0,r=0,sub,ans=0;
	for(int i=1;i<=n;i++){
		cand+=buc[i];
		if(cand!=buc[i]){
			cand-=buc[i];
		}
	}
} 
