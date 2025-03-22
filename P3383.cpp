#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n,q,k;
bool prime1[int(1e8+5)];
vector <int> prime;
void ai1prime(int x){
    for(int i=2;i<=x;i++){
        if(prime1[i]==0){
            prime.push_back(i);
        }
        for(int p=0;p<prime.size() and i*prime[p]<x;p++){
            prime1[i*prime[p]]=1;
            if(i%prime[p]==0){
                    break;
                }
            }
    }
}
int main(){
    scanf("%d",&n);
    ai1prime(n);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&k);
        printf("%d\n",prime[k-1]);
    }
}