#include <iostream>
using namespace std;
//need 100 O(less n2)
/* TLE3 85 O(n2logn)
struct score{
    int scl[100005];
    int l;
}list;
void pulg(score &a,int x){
    int tmp=a.l+1;
    for(int i=1;i<=a.l;i++){
        if(a.scl[i]<x){
            tmp=i;break;
        }
    }
    for(int i=++a.l;i>tmp;i--){
        a.scl[i]=a.scl[i-1];
    }
    a.scl[tmp]=x;
}
int main(){
    //freopen("live.in","r",stdin);
    //freopen("live.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,w,st;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>st;
        pulg(list,st);
        cout<<list.scl[max(1,i*w/100)]<<' ';
    }
}
*/
int box[605];
int main(){//100 AC
    ios::sync_with_stdio(0);
    int n,w,tmp;
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        box[tmp]++;
        int stmp=0;
        for(int j=600;j>=0;j--){
            stmp+=box[j];
            if(stmp>=max(1,i*w/100)){
                cout<<j<<' ';
                break;
            }
        }
    }
    return 0;
}