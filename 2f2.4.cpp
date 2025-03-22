#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c and a+c>b and b+c>a){
		int P=(a+b+c)/2;
		double ans=P*(P-a)*(P-b)*(P-c);
		cout<<sqrt(ans);
	}
	else{
		cout<<"UKE!!!";
	}
	return 0;
}
