#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
struct node {
	int people,id,page;
	bool operator<(const node &s1)const {
		if (people < s1.people) {
			return true;
		}
		else if (id < s1.id) {
			return true;
		}
		else {
			return false;
		}
	}
};

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c > '9' or c < '0') {
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while (c <= '9' and c >= '0') {
		igt = (igt << 3) + (igt << 1) + c - '0';
		c = getchar();
	}
	return igt*sgn;
}
set <node> query;
int main() {
	int n=read();
	int m = read();
	int q = read();
	int opt;
	int x, y;
	for (int i = 1; i <= q; i++) {
		opt = read();
		if (opt == 1) {
			x = read(); y = read();
			query.insert({x,y});
		}
		if (opt == 2) {
			x = read();
			for(int j=1;j<=m;j++){
				query.insert({ x,j });
			}
		}
		if (opt == 3) {
			x = read(); y = read();
			if (query.find({ x,y })==query.end()) {
				cout << "No\n";
			}
			else{
				cout << "Yes\n";
			}
		}
	}
	return 0;
}