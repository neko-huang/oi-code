#include <iostream>
using namespace std;
long long gcd(int a, int b) { return b ? gcd(b, a % b) :a ; }
int main() { 
	int a, b; 
	cin >> a >> b; 
	cout<<gcd(a, b); 
}