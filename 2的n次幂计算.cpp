#include<iostream>
using namespace std;
int a[11451400]={0},ct;long long len=0;
int main(){
	cin>>ct;
	a[0]=1;
	int temp;
	for(int i=1;i<=ct;i++){
		if(a[len]>4){
			len++;
		}
		for(int o=len;o>=0;o--){
			a[o]*=2;
		}
		for(int o=0;o<=len;o++){
			temp=a[o]/10;
			a[o+1]+=temp;
			a[o]%=10;
		}
		cout<<i<<' ';
		for(int o=len;o>=0;o--){
			cout<<a[o];
		}
		cout<<'\n';
	}
	return 0;
}
