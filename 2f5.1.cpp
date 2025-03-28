#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string tmp;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (tmp.find("AAAAAAAAAAAAA")!=string::npos or tmp.find("TTTTTTTTTTTTT")!=string::npos) {
			cout << "Yes"<<endl;
		}
		else {
			cout << "No"<<endl;
		}
	}
}
