#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;
const ll maxn = ll(22000000 + 10);

long long len[maxn];
char s[maxn],afs[maxn];
ll tot;

int main() {

	cin >> (s + 1);
	afs[0] = '#';
	afs[++tot] = '@'; ll tmp = strlen(s + 1);
	for (ll i = 1; i <= tmp; i++) {
		afs[++tot] = s[i];
		afs[++tot] = '@';
	}

	len[1] = 1;
	//manacher 
	ll l=0, r=1;//���ǻ�������
	ll ans=0;
	for (ll i = 2; i <= tot; i++) {
		if (i <= r) {//��������
			len[i] = min( len[l + r - i], r - i+1);//r-i+1: (��С)���ľ��� len[l+r-i]: �Գ��Ծ���
		}
		while (afs[i - len[i]] == afs[i + len[i]]) {//��չ
			len[i]++;
		}
		//|�����Լ�,����-1
		//v
		if (i + len[i] - 1 > r) {//��������,upd
			r = i + len[i] - 1;
			l = i - len[i] + 1;
		}
		ans = max(ans, len[i]);
	}
	printf("%lld", ans-1);//-1
	return 0;
}