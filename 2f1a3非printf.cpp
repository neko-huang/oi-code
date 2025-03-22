#include<iostream> 
using namespace std;
#define PI 3.14
int flgg=0;
double getdb(double a){
	int s=a;
	a-=s;
	if(a==0){
		flgg++;
	}
	return a;
}
double dbfish(double a,long b){//��.ȡ�� 
	int s=a;
	a-=(s/b)*b;
	return a;
}
int main() { 
	int r;
	cin>>r;
	double xiao=getdb(r*r*PI);
	int a=r*r*PI;
	int ge=a%10;
	a/=10;
	if(flgg==0){
		cout<<a<<ge<<xiao;
	}
	if(flgg==1){
		cout<<a<<ge<<".00";
	}
	return 0; 
}
