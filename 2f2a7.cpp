#include <iostream>
using namespace std;
int main(){
	int max=0;
	int a[10]={0};
	for(int i=1;i<=3;i++){
		cin>>a[i];
		if(a[i]>max){
			max=a[i];
		}
	}
	cout<<max;
	return 0;
}
