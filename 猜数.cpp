#include <iostream>
#include <ctime>
using namespace std;
long long random(long long seed){
	seed/=100;
	seed*=92;
	seed%10;
	seed=seed++ + ++seed;
	seed*=seed*seed*seed*seed*seed*seed*seed*seed*seed*seed*seed*seed;
	return seed;
}
int flgg=0;long long temp=0;int t=0;
/*
int main1(){
	cout<<"����������";
	long long seed;
	cin>>seed;
	int ans=random(seed);
	while(flgg==0){
		cout<<'\n'<<'\n'<<"����"<<'\n';
		cin>> temp;
		if(temp>ans){
			cout<<"����";
		}
		if(temp<ans){
			cout<<"С��";
		}
		if(temp==ans){
			flgg=1;
		}
		t++;
		temp=0;
	}
	cout<<"����!�����"<<time<<"��";
	return 0; 
} 
*/
int main() {
	srand((unsigned)time(NULL));
	int ans = rand();
	while (flgg == 0) {
		cout << '\n' << '\n' << "����" << '\n';
		cin >> temp;
		if (temp > ans) {
			cout << "����";
		}
		if (temp < ans) {
			cout << "С��";
		}
		if (temp == ans) {
			flgg = 1;
		}
		t++;
		temp = 0;
	}
	cout << "����!�����" << t << "��";
	return 0;
}
