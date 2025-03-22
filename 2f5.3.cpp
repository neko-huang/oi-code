#include <iostream>
using namespace std;
void usefor() {//5times
	for (int i = 1; i <= 5; i++) {
		cout << "2fohh\n";
	}
	return;
}
void usewhile() {//5times
	int i = 1;
	while (i <= 5) {
		cout << "2fohh\n";
		i++;
	}
	return;
}
int main() {
	//usefor() == usewhile()
	usefor();
	cout <<'\n'; 
	usewhile();
}