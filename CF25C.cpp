#include <iostream>
#include <vector>

using namespace std;
const int maxn = int(3e2 + 5);

struct node {
	int v, w;
};

int dis[maxn][maxn];
vector <node> G[maxn];

int read() {
	int igt = 0, sgn = 1;
	char c = getchar();
	while (c < '0' or c>'9'){
		if (c == '-') {
			sgn = -1;
		}
		c = getchar();
	}
	while(c<='9' and c>='0')
}
int main() {
	int 
}