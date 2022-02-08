//LCA using Sparse table
// Time complexity O(nlogn,logn)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
int const mx = 200001;
int level[mx];
int P[mx][22]; // sparse table
int T[mx]; //parent
vv g[mx];
void dfs(int s,int u,int dep){
   T[u]=s;
   level[u]=dep;
   for(int i=0;i<g[u].size();i++){
      int x=g[u][i];
      if(x==s) continue;
      dfs(u,x,dep+1);
   }
}
void LCA_init(int n){
   RESET(P,-1);
   for(int i=0;i<n;i++) P[i][0]=T[i];

   for(int j=1;(1<<j)<n;j++){
    for(int i=0;i<n;i++){
        if(P[i][j-1]!=-1)
            P[i][j]=P[P[i][j-1]][j-1];
    }
   }
}
int LCA_query(int n,int p,int q){
    int tmp,log=1;
    if(level[p]<level[q])
        tmp=p,p=q,q=tmp;

    while(1){
        int next=log+1;
        if((1<<next)>level[p]) break;
        log++;
    }
    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q])
            p=P[p][i];
    }
    if(p==q) return p;
    for(int i=log;i>=0;i--){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];
    }
    return T[p];
}
int main()
{
    int n;
    cin>>n;
    //dfs(0,0,0);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].pb(y);
        g[y].pb(x);
    }
    LCA_init(n);
    int ans=LCA_query(n,4,5);
    cout<<ans<<endl;
}

