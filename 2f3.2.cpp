#include <iostream>
using namespace std;
int f3_2_1_1() {
	for (int i = 0; i < 5; i++) {
		cout << "hello"<<'\n';
	}
	for (int i = 0; i < 5; i++) {
		cout << "bye"<<'\n';
	}
	return 0;
}
int f3_2_1_3() {
	int i = 0;
	while (i < 10) {
		i++;
		if (i > 5) {
			cout << "bye" << '\n';
			continue;
		}
		cout << "hello"<<'\n';
	}
	return 0;
}
int f3_2_1_2() {
	int i = 0;
	while (i < 5) {
		cout << "hello"<<'\n';
		i++;
	}
	while (i > 0) {
		cout << "bye"<<'\n';
		i--;
	}
	return 0;
}
int f3_2_2_1() {
	int i = 0;
	while (i < 5) {
		i++;
		cout << "hello" << '\n' << "bye"<<'\n';
	}
	return 0;
}
int f3_2_2_2() {
	int i = 0;
	while (i < 10) {
		i++;
		if (i % 2 == 0) {
			cout << "bye"<<'\n';
			continue;
		}
		cout << "hello"<<'\n';
	}
	return 0;
}
int f3_2_2_3() {
	int i = 0;
	while (i < 10) {
		i++;
		if (i % 2 == 0) {
			cout << "bye";
		}
		else {
			cout << "hello";
		}
		cout << '\n';
	}
	return 0;
}
int main() {
	f3_2_2_3();
}