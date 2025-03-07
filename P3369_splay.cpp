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
int rt=0;//root
int idx=0;//node cnt
int newnode(int x){
    //node cnt->quan zhi idx->bian hao
    tree[++idx].cnt=x;
    tree[idx].sz=1; 
    return idx;
}
bool get(int x){
    //left or right? true->right false->left
    return tree[tree[x].fa].s[1]==x;
}
void upd(int x){
    //oh!! my size
    tree[x].sz = tree[tree[x].ls].sz + tree[tree[x].rs].sz + 1;
}
//1 error
void clear(int x){
    //si!
    tree[x].fa=tree[x].sz=tree[x].cnt=tree[x].s[0]=tree[x].s[1]=0;
}
void rotate(int x){
    int f = tree[x].fa, gf = tree[f].fa;bool c = get(x);//father grandfather //left or right
    if(tree[x].s[!c]){//im father 
        tree[tree[x].s[!c]].fa=f;//my son is my grandson yet//after 3 steps
    }
    tree[f].s[c] = tree[x].s[!c];//1 step
    tree[x].s[!c]=f;//im father now!     |
    tree[f].fa = x;//gong gu di wei also V

    tree[x].fa = gf;//jia jie
    if(gf){
        tree[gf].s[f==tree[gf].rs]=x;//jia jie
    }
    upd(f);//wei
    upd(x);//wei
    return ;
}
//3 errors
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
        now=tree[now].s[x>tree[now].cnt];//look and find where to del
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
        return ;
    }
    //fen lei 2:yes! have lson(whather you mei you rson)
    while(tree[che].s[1]){
        che=tree[che].s[1];
    }//pre father 's ltree 's rtree 's max
    tree[che].s[1]=tree[now].s[1];
    tree[tree[now].s[1]].fa=che;
    tree[tree[now].s[0]].fa=0;//wo shi rt
    clear(now);
    //finish!
    //wei hu ping heng
    upd(che);
    splay(che);
}//wow
//hehe! 3errs checked
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
        if(x<tree[tree[now].s[0]].sz+1){//1 kai tou xia biao//yao +1//+3+3+3
            now=tree[now].s[0];
        }
        else if(x==tree[tree[now].s[0]].sz+1){
            break;
        }
        else{
            x-=tree[tree[now].s[0]].sz;
            x--;
            now=tree[now].s[1];
        }
    }
    splay(now);return tree[now].cnt;
}
//wow 1 err -60pts
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