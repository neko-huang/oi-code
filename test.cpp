#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#include <iostream>
using namespace std;
struct Gint {
	int len, a[5000] = {0};
	Gint(int i=0) {
		for (len = 1; i != 0; len++) {
			a[len] = i % 10; i /= 10;
		}
		len--;
	}
	int& operator[](int x){
		return a[x];
	}
	void j(int l) {
		len = l;
		for (int i = 1; i <= len; i++) {
			a[i + 1] += a[i] / 10; a[i] %= 10;
		}
		for (;!a[len];) {
			len--;
		}
	}
	void p() {
		for (int i = max(len, 1); i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
};
Gint operator+(Gint a, Gint b) {
	Gint c;
	int len = max(a.len, b.len);
	for (int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
	}
	c.j(len + 1);
	return c;
}
Gint operator*(Gint a, int b) {
	Gint c;
	int len = a.len;
	for (int i = 1; i <= len; i++) {
		c[i] = a[i] * b;
	}
	c.j(len + 11);
	return c;
}
int main(){
    Gint a(11),b(11);
    Gint d;
    Gint f;
    d=a*11;
    f=a+b;
}