#include <iostream>
using namespace std;
int main(){
	double a;
	cin>>a;
	if(a<=4){
		cout<<a*5;
	}
	else{
		double b=a-4;
		cout<<4*5+b*4;
	}
	return 0;
}
