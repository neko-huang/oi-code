#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=int(2e5+5);

long long cnt[maxn*3];

long long read(){
	long long igt=0,sgn=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-'){
			sgn=-1;
		}
		c=getchar();
	}
	while(c<='9' and c>='0'){
		igt=(igt<<3)+(igt<<1)+c-'0';
		c=getchar();
	}
	return igt*sgn;
}

long long a[maxn];

int main(){
	
	long long n=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
	}
	
	for(long long i=1;i<=n;i++){
	
		if(i>a[i])cnt[i-a[i]]++;
	}
	long long ret=0;
	for(long long i=1;i<=n;i++){
		if(cnt[a[i]+i]){
			ret+=cnt[a[i]+i];	
		}
	}
	
	cout<<ret;
	return 0;
}