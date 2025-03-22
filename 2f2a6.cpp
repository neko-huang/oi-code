#include <iostream>
using namespace std;
int main(){
	double s1,s2,b1,b2;
	cin>>s1>>s2>>b1>>b2;
	if(s1*s2>b1*b2){
		cout<<b1*b2;
		return 0;
	}
	cout<<s1*s2;
	return 0;
}
