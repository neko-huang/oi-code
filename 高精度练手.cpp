//¸ß¾«¶È
#include <iostream>
#include <string>
int a1[114514],b1[114514];
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int len;
	a.length()>b.length()?len=a.length():len=b.length();
	for(int i=a.length()-1,j=0;i>=0;i--,j++){
		a1[j]=a[i]-'0'; 
	}
	for(int i=b.length()-1,j=0;i>=0;i--,j++){
		b1[j]=b[i]-'0'; 
	}
	for(int i=0;i<len;i++){
		b1[i]+=a1[i];
	}
	int temp;
	for(int i=0;i<len;i++){
		temp=b1[i]/10;
		b1[i+1]+=temp;
		b1[i]%=10;
	}
	if(b1[len]!=0){
		len++;
	}
	for(int i=len-1;i>=0;i--){
		cout<<b1[i];
	}
	return 0;
}
