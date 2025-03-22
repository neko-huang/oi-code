#include <iostream>
using namespace std;
/*
int main1() {
	//ͬ
	int s = 0; char ch;//ch Сд+
	while (cin>>ch and ch!='.'){
		if ('a' <= ch and ch <= 'z') {
			s++;
		}
	}
	cout << s;
	return 0;
}
*/
int main() {
	int s = 0; char ch;//ch Сд+
	while (true) {
		cin >> ch;
		if (ch == '.') { break; }
		if ('a' <= ch and ch <= 'z') {
			s++;
		}
	}
	cout << s;
	return 0;
}