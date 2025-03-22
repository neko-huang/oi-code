#include <iostream>
using namespace std;
int main(){
	double m,kg;
	cin>>kg>>m;
	int BMI=kg/(m*m);
	if(BMI<18){
		cout<<"low";
	}
	else if(18<=BMI<=24){
		cout<<"middle";
	}
	else{
		cout<<"fat";
	}
}
