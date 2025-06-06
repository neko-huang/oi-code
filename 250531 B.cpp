#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> A;

int main() {
	int n; cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	cout << A.size() << '\n';
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' ';
	}
	return 0;
}