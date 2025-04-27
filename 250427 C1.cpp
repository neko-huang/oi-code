#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
struct node {
	int people, id, page;
	bool operator<(const node& s1)const{
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
const int maxn = int(2e5 + 5);
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
	return igt * sgn;
}
node change[maxn];
node query[maxn];
bool cmp(node a, node b) {
	return a < b;
}
int main() {
	int n=read(),m=read(),q=read();
	int cnt = 1;
	int tot = 1;
	for (int i = 1; i <= q; i++) {
		int opt = read();
		if (opt == 1) {
			int x = read(), y = read();
			change[cnt] = { x,cnt++,y};
		}
		else if (opt == 2) {
			int x = read();
			for (int j = 1; j <= m; j++) {
				change[cnt] = { x,cnt++,j };
			}
		}
		else {
			int x = read(), y = read();
			query[tot] = { x,tot++,y };
		}
	}
	sort(change + 1, change + 1 + cnt, cmp);
	sort(query + 1, query + 1 + tot, cmp);

}