#include <iostream>
using namespace std;
const int maxn=int(1e5+5);   
#define ls s[0]
#define rs s[1]
struct node{
    int s[2]={0,0};//sheng min cuo wu
    int fa=0,sz=0;
    int cnt=0;//cnt shi quan zhi(dian quan)
}tree[maxn];
int rt=0;
int idx=0;
int newnode(int x){
    tree[++idx].cnt=x;
    tree[idx].sz=1;
    return idx;
}
bool get(int x){
    return tree[tree[x].fa].s[1]==x;
}
void upd(int x){
    tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
}
void clear(int x){
    tree[x].fa=tree[x].sz=tree[x].cnt=tree[x].s[0]=tree[x].s[1]=0;
}
void rotate(int x){
    int f=tree[x].fa,gf=tree[f].fa,c=get(x);
    tree[f].s[c]=tree[x].s[!c];
    if(tree[x].s[!c]){
        tree[tree[x].s[!c]].fa=f;
    }
    tree[x].s[!c]=f;
    tree[f].fa=x;
    if(gf){
        tree[gf].s[f==tree[gf].ls]=x;
    }
    upd(f);
    upd(x);
    return ;
}
void splay(int x){
    for(int f=tree[x].fa;f=tree[x].fa,f;rotate(x)){
        if(tree[f].fa){
            rotate(get(x)==get(f)?f:x);
        }
    }
    rt=x;
}
void ins(int x){
    int now=rt,f=0;
    while(now){
        f=now,now=tree[now].s[x>tree[now].cnt];
    }
    now=newnode(x);
    tree[now].fa=f;
    tree[f].s[x>tree[f].cnt]=now;
    splay(now);
}
void del(int x){
    int now=rt,f=0;
    while(tree[now].cnt!=x and now){//and now? bao zheng fei!kong ji
        f=now;
        now=tree[now].s[tree[now].cnt>x];
    }
    // fen lei 0:kong ji
    if(!now){
        splay(f);
        return ;
    }
    splay(now);
    //fen lei 1:no lson(whather you mei you rson)
    int che=tree[now].s[0];
    if(!che){
        rt=tree[now].s[1];
        tree[tree[now].s[1]].fa=0;
        clear(now);
    }
    //fen lei 2:yes! you lson(whather you mei you rson)
    while(tree[che].s[1]){
        che=tree[che].s[1];
    }//zuo zi shu de zui da zhi
    tree[che].s[1]=tree[now].s[1];
    tree[tree[now].s[1]].fa=che;
    tree[tree[now].s[0]].fa=0;//wo shi rt
    clear(now);
    //finish!
    //wei hu ping heng
    upd(che);
    splay(che);
}//wow
int rnk(int x){
    int now=rt;int res=1;int f;
    while(now){
        f=now;
        if(x<=tree[now].cnt){
            now=tree[now].s[0];
        }
        else{
            res+=tree[tree[now].s[0]].sz+1;
            now=tree[now].s[1];
        }
    }
    splay(f);
    return res;
}
int kth(int x){
    int now=rt;
    while(now){
        if(x<=tree[tree[now].s[0]].sz){
            now=tree[now].s[0];
        }
        else if(x==tree[tree[now].s[0]].sz){
            break;
        }
        else{
            x-=tree[tree[now].s[0]].sz;
            now=tree[now].s[1];
        }
    }
    splay(now);return tree[now].cnt;
}
int pre(int x){
    int now=rt;int ans=0;int f;
    while(now){
        f=now;
        if(tree[now].cnt>=x){
            now=tree[now].s[0];
        }
        else{
            ans=tree[now].cnt;
            now=tree[now].s[1];
        }
    }
    splay(f);
    return ans;
}
int nxt(int x){
    int now=rt;int ans=0;int f;
    while(now){
        f=now;
        if(tree[now].cnt<=x){
            now=tree[now].s[1];
        }
        else{
            ans=tree[now].cnt;
            now=tree[now].s[0];
        }
    }
    splay(f);
    return ans;
}
int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c>='0' and c<='9'){
        igt=igt*10+c-'0';
        c=getchar();
    }
    return igt*sgn;
}
int main(){
    int n=read();
    int opt,x;
    while(n--){
        opt=read();
        x=read();
        if(opt==1){
            ins(x);
        }
        else if(opt==2){
            del(x);
        }
        else if(opt==3){
            printf("%d\n",rnk(x));
        }
        else if(opt==4){
            printf("%d\n",kth(x));
        }
        else if(opt==5){
            printf("%d\n",pre(x));
        }
        else{
            printf("%d\n",nxt(x));
        }
    }
    return 0;
}