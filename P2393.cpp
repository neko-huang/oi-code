#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    long double a,ans=0;
    while(scanf("%Lf",&a)!=EOF){
        ans+=a*1000000;
    }
    printf("%.5Lf",ans/1000000);
    return 0;
}