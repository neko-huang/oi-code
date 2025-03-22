//AC
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct pos{
    double x,y,z;
};
pos cli[50004];
bool cmp(pos a,pos b){
    return a.z>b.z;
}
double f2(double a){
    return a*a;
}
double dis(pos a,pos b){
    return sqrt(f2(a.x-b.x)+f2(a.y-b.y)+f2(a.z-b.z));
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cli[i].x>>cli[i].y>>cli[i].z;
    }
    sort(cli+1,cli+n+1,cmp);
    double ans=0;
    for(int i=1;i<n;i++){
        ans+=dis(cli[i],cli[i+1]);
    }
    printf("%.3lf",ans);
}