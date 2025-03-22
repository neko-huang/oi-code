#include <iostream>
#include <string.h>
using namespace std;
int num[5];
int main(){
    string ipp;
    cin>>ipp;
    int dot=0;bool loos=0,ztest=0;
    for(int i=0;i<ipp.length();i++){
        if(ipp[i]=='.'){
            dot++;
        }
        if((i+1)<=ipp.length()){
            if(ipp[i]=='.' and ipp[i+1]=='.'){
                loos=1;
            }
            if((i+2)<=ipp.length()){
                if(ipp[i]=='.' and ipp[i+1]=='0' and (ipp[i+2]>='0' and ipp[i+2]<='9')){
                    ztest=1;
                }
            }
        }
    }
    if(dot!=3){//1
        cout<<"ERROR 1";
        return 0;
    }
    if(loos){//2
        cout<<"ERROR 2";
        return 0;
    }
    if(ipp[0]=='0' and ipp[1]!='.'){
        ztest=1;
    }
    if(ztest){//3
        cout<<"ERROR 3";
        return 0;
    }
    int li=1;
    for(int i=0;ipp[i]!='\0';i++){
        if(ipp[i]=='.'){
            li++;
            continue;
        }
        num[li]=num[li]*10+ipp[i]-'0';
    }
    if(num[1]>255 or num[2]>255 or num[3]>255 or num[4]>255){
        cout<<"ERROR 4";
        return 0;
    }
    cout<<"RIGHT";
    return 0;
}