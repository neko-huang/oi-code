#include <iostream>
using namespace std;
int read(){
    int n;
    scanf("%d",&n);
    return n;
}
const int maxn=int(1e5+5);
int T[maxn],M[maxn];
int t[maxn],m[maxn];
int main(){
    int n=read(),L=read(),R=read();
    for(int i=1;i<=n;i++){
        T[i]=read();
        T[i]/=2;
        M[i]=read();
    }
    for(int i=1;i<=n;i++){
        t[i]=read();
        m[i]=read();
    }
    for(int i=1;i<=n;i++){
        if(i>=L and i<=R){
            printf("System Error\n");
        }
        else if(M[i]>m[i]){
            printf("Memory Limit Exceeded\n");
        }
        else if(T[i]>t[i]){
            printf("Time Limit Exceeded\n");
        }
        else{
            printf("Accepted\n");
        }
    }
}