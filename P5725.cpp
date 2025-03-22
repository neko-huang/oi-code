#include <iostream>
#include <cmath>
using namespace std;
double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    double lis[7][7];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=2;j++){
            cin>>lis[i][j];
        }
    }
    double ans=0;
    ans+=dis(lis[1][1],lis[1][2],lis[2][1],lis[2][2]);
    ans+=dis(lis[1][1],lis[1][2],lis[3][1],lis[3][2]);
    ans+=dis(lis[2][1],lis[2][2],lis[3][1],lis[3][2]);
    printf("%.2lf",ans);
    return 0;
}