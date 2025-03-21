#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
struct Gint {
	int l, a[127] = {0};
	Gint(int i=0) {
		for (l = 1; i != 0; l++) {
			a[l] = i % 10; i /= 10;
		}
		l--;
	}
	int& operator[](int x){
		return a[x];
	}
	void j(int l1) {
		l = l1;
		for (int i = 1; i <= l; i++) {
			a[i + 1] += a[i] / 10; a[i] %= 10;
		}
		for (;!a[l];) {
			l--;
		}
	}
	void p() {
		for (int i = max(l, 1); i >= 1; i--) {
			printf("%d", a[i]);
		}
	}
};
Gint operator+(Gint a, Gint b) {
	Gint c;
	int len = max(a.l, b.l);
	for (int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
	}
	c.j(len + 1);
	return c;
}
Gint operator*(Gint a, int b) {
	Gint c;
	int len = a.l;
	for (int i = 1; i <= len; i++) {
		c[i] = a[i] * b;
	}
	c.j(len + 11);
	return c;
}
Gint max(Gint c,Gint b){
    if(c.l==b.l){
        for(int i=c.l-1;i>=0;i--){
            if(c.a[i]==b.a[i]){
                continue;
            }
            return c.a[i]>b.a[i]?c:b;
        }
        return c;
    }
    else{
        return c.l>b.l?c:b;
    }
}
int n,m;
int maze[127][127];
// bigint
Gint dp[127][127];
Gint ans;
Gint f2[127];
int main(){
    f2[0]=Gint(1);
    for(int i=1;i<=127;i++){
        f2[i]=f2[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>maze[i][j];
        }
    }
    for(int t=1;t<=n;t++){
        for(int i=1;i<=m;i++){//j-i+1是队列长度
            for(int j=m;j>=i;j--){
                dp[i][j]=max(dp[i-1][j]+f2[m-j+i-1]*maze[t][i-1],max(dp[i][j+1]+f2[m-j+i-1]*maze[t][j+1],dp[i][j]));
            }
        } 
        Gint fd;
        for(int i=1;i<=m;i++){
            fd=max(fd,dp[i][i]+f2[m]*maze[t][i]);
        }
        ans=ans+fd;
        memset(dp,0,sizeof(dp));
    }
    ans.p();
    return 0;
}