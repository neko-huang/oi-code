#include <iostream>
using namespace std;
bool kill[4095][4095];
void killed(int side,int lx,int ly){
    if(side==1){
        kill[lx][ly]=1;
        return ;
    }
    killed(side/2,lx+side,ly);
    killed(side/2,lx,ly+side);
    killed(side/2,lx+side,ly+side);
}
int main(){
    
}