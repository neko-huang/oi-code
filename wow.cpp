#include<bits/stdc++.h>
using namespace std;
struct Edge{
  int next,to;
} edge[200005];
struct Tree{
  int left,right,deepest;
} tree[800005];
int head[200005],size1[200005],fa[200005],son[200005],deep[200005],top[200005],id[200005],dfsid[200005];
int cnt=1,n,m,a,b,c,dfsord;
char x;
inline int read()//快读
{
  char ch=getchar();
  int f=1,x=0;
  while (ch<'0' || ch>'9')
  {
    if (ch=='-') f=-1;
    ch=getchar();
  }
  while (ch>='0' && ch<='9')
  {
    x=x*10+ch-'0';
    ch=getchar();
  }
  return f*x;
}
inline void add(int u,int v)//加边
{
  edge[cnt].to=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void build(int x,int l,int r)//建树
{
  tree[x].left=l;
  tree[x].right=r;
  tree[x].deepest=-1;//注意要赋值为-1
  if (r-l>1)
  {
    build(x*2,l,(l+r)/2);
    build(x*2+1,(l+r)/2,r);
  }
}
void change(int x,int l,int r)
{
  if (l<=tree[x].left && r>=tree[x].right) tree[x].deepest=l;//只有一个元素时标记的最深的节点就是它自己
  else
  {
    int mid=(tree[x].left+tree[x].right)/2;
    if (l<mid) change(x*2,l,r);
    if (r>mid) change(x*2+1,l,r);
    tree[x].deepest=max(tree[x*2].deepest,tree[x*2+1].deepest);//取两段上最深的节点
  }
}
int query(int x,int l,int r)
{
  if (l<=tree[x].left && r>=tree[x].right) return tree[x].deepest;
  else
  {
    int mid=(tree[x].left+tree[x].right)/2,ans=-1;//同样注意初值
    if (l<mid) ans=max(ans,query(x*2,l,r));
    if (r>mid) ans=max(ans,query(x*2+1,l,r));
    return ans;
  }
}
void dfs1(int x,int f,int dep)
{
  deep[x]=dep;
  fa[x]=f;
  size1[x]=1;
  int mx=-1;
  for (int i=head[x];i;i=edge[i].next)
  {
    int y=edge[i].to;
    if (y==f) continue;
    dfs1(y,x,dep+1);
    size1[x]+=size1[y];
    if (size1[y]>mx)
    {
      mx=size1[y];
      son[x]=y;
    }
  }
}
void dfs2(int x,int topf)
{
  top[x]=topf;
  id[x]=++dfsord;
  dfsid[dfsord]=x;//因为是输出节点原序号，这里得到dfs序对应的节点序号
  if (!son[x]) return;
  dfs2(son[x],topf);
  for (int i=head[x];i;i=edge[i].next)
  {
    int y=edge[i].to;
    if (y==fa[x] || y==son[x]) continue;
    dfs2(y,y);
  }
}
inline void uprange(int u)
{
  change(1,id[u],id[u]+1);
}
inline int qrange(int u,int v)
{
  int ans=-1;
  while (top[u]!=top[v])
  {
    if (deep[id[u]]<deep[id[v]]) swap(u,v);
    ans=query(1,id[top[u]],id[u]+1);
    if (ans!=-1) return dfsid[ans];//只要找到就返回
    u=fa[top[u]];
  }
  if (deep[u]>deep[v]) swap(u,v);
  ans=query(1,id[u],id[v]+1);
  return dfsid[ans];
}
int main()
{
  n=read();m=read();
  for (int i=1;i<n;i++)
  {
    a=read();b=read();
    add(a,b);
    add(b,a);
  }
  dfs1(1,0,1);
  dfs2(1,1);
  build(1,1,n+1);
  change(1,1,2);//注意先将根节点打上标记
  for (int i=1;i<=m;i++)
  {
    cin>>x;
    a=read();
    if (x=='C') uprange(a);
    else printf("%d\n",qrange(a,1));
  }
  return 0;
}
