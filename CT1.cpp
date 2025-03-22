#include <iostream>
using namespace std;
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  for(int i=1;i<=m;i++){
  	x++;
    if(x%(n+1)==0){
    	x=1;
    }
  }
  cout<<x;
  return 0;
}