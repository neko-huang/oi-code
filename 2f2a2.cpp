#include <iostream>
using namespace std;
int main(){
	long long a,b,bk;
	cin>>a>>b;
	bk=a;
	a=b;
	b=bk;
	cout<<a<<' '<<b;
	return 0;
}
