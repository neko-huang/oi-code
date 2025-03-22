#include<iostream>
using namespace std;
unsigned short a[191981000]={0},ct;
void logpow(long long x,long long y){
	long long len=0;
	a[0]=1;
	long long temp;
	cout<<"正在计算中"<<'\n'<<'\n';
	for(long long i=1;i<=y;i++){
		if(a[len]>4){
			len++;
		}
		for(long long o=len;o>=0;o--){
			a[o]*=x;
		}
		for(long long o=0;o<=len;o++){
			temp=a[o]/10;
			a[o+1]+=temp;
			a[o]%=10;
		}
		cout<<i<<' ';
		for(long long o=len;o>=0;o--){
			cout<<a[o];
		}
		if(i==y){
			return ;
		}
		cout<<'\n';
	}
	cout<<'\n'<<'\n'<<"计算完毕"; 
	return ;
}
void pow(long long x,long long y){
	long long len=0;
	a[0]=1;
	long long temp;
	cout<<"正在计算中"<<'\n'<<'\n';
	for(long long i=1;i<=y;i++){
		if(a[len]>4){
			len++;
		}
		for(long long o=len;o>=0;o--){
			a[o]*=x;
		}
		for(long long o=0;o<=len;o++){
			temp=a[o]/10;
			a[o+1]+=temp;
			a[o]%=10;
		}
	}
	for(long long o=len;o>=0;o--){
		cout<<a[o];
	}
	cout<<'\n'<<'\n'<<"计算完毕";
	return ;
}
/*int olpow(long long x,long long y){
	long long len=0;
	a[0]=1;
	long long temp;
	for(long long i=1;i<=y;i++){
		if(a[len]>4){
			len++;
		}
		for(long long o=len;o>=0;o--){
			a[o]*=x;
		}
		for(long long o=0;o<=len;o++){
			temp=a[o]/10;
			a[o+1]+=temp;
			a[o]%=10;
		}
	}
	for(long long o=len;o>=0;o--){
		return a[o];
	}
}*/
int main(){
	long long x,y;
	cin>>x>>y;
	pow(x,y);
	return 0;
}
