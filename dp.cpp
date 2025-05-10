#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main() {
	//freopen("input.txt", "w",stdout);
	srand(time(0));
	int h = (rand() % 10) + 1;
	int w = (rand() % 10) + 1;
	cout << h <<' '<< w<<'\n';
	bool flag = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int tmp = rand() % 6;
			if (tmp == 4) {
				cout << '#';
				continue;
			}
			if (tmp == 3 and !flag) {
				cout << 'E';
				flag = 1;
				continue;
			}
			if (i == h and j == w) {
				if (!flag) {
					cout << 'E';
					continue;
				}
			}
			cout << '.';
		}
		cout << '\n';
	}
	return 0;
}