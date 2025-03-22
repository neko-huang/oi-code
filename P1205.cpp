#include <iostream>
#include <string.h>
using namespace std;
string old[15];
string now[15];
char cold[15][15];
char cnow[15][15];
int n;
bool check1(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnow[i][j]!=cold[j][n-i+1]){
                return 0;
            }
        }
    }
    return 1;
}
bool check2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnow[i][j]!=cold[n-i+1][n-j+1]){
                return 0;
            }
        }
    }
    return 1; 
}
bool check3(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnow[i][j]!=cold[n-j+1][i]){
                return 0;
            }
        }
    }
    return 1;
}
bool check4(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnow[i][j]!=cold[n-i+1][j]){
                return 0;
            }
        }
    }
    return 1;
}
bool check5(){
    
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>old[i];
    }
    for(int i=1;i<=n;i++){
        cin>>now[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            cold[i][j+1]=old[i][j];
            cnow[i][j+1]=now[i][j];
        }
    }
}