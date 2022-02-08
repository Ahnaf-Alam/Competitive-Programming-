#include<bits/stdc++.h>
using namespace std;
//#define pb push_back
#define infinity 1<<30 //2^30
typedef long long ll;
vector<int>v1,v2;
struct node{
   int u, cost;
   node(int _u,int _cost){
      u = _u;
      cost = _cost;
   }
   bool operator < (const node& p) const { return cost> p.cost; } // operator overloading.
};
void dijkstra(int s,vector<vector<int> >g,vector<vector<int> >cost,int path[]){
  int dis[200001];
  for(int i=0;i<200001;i++) dis[i]=infinity;
  priority_queue<node> q;
  q.push(node(s,0));
  dis[s]=0;

   while(q.size()>0){
     node top= q.top();
     q.pop();
     int u=top.u;
      for(int i=0;i<g[u].size();i++){
          int v=g[u][i];
          if(dis[u]+cost[u][i]<dis[v]){
              dis[v]=dis[u]+cost[u][i];
              q.push(node(v,dis[v]));
              path[v]=u;
          }
      }
      /*for(int i=1;i<=n;i++){
        cout<<s<<" --> "<<i<<" = "<<dis[i]<<endl;
      }*/
    }
}
void print(int path[],int ds,int s,int f1,int f2,int f3){
    if(ds==s){
            //cout<<s<<endl;
            return;
    }

    print(path,path[ds],s,f1,f2);
    if(f1==1 && f2==0)
    v1.push_back(path[ds]);
    else if(f1==0 && f2==1)
    v2.push_back(path[ds]);
    else if(f1==0 && f2==0 &&f3==1)
    v3.push_back(path[dis]);
    //cout<<path[ds]<<" --> ";
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,m,a,b,c,x,y,cnt=0;
    cin>>n>>m>>a>>b>>c;
    int cst[m+3],x1[n+3],path[n+3];
    for(int i=0;i<m;i++) cin>>cst[i];

    vector<vector <int > > g(n+3),cost(n+3);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x].push_back(1);
        cost[y].push_back(1);
    }
    dijkstra(a,g,cost,path);
    print(path,b,a,1,0,0);
    v1.push_back(b);
    dijkstra(b,g,cost,path);
    print(path,c,b,0,1,0);
    v2.push_back(c);
    path(path,c,a,0,0,1);
    v3.push_back(c);
    path()
    for(int i=0;i<v1.size()-1;i++){
         x1[v1[i]]=v1[i+1];
         x1[v1[i+1]]=v1[i];
    }
    for(int i=0;i<v2.size()-1;i++){
        if(x1[v2[i]]==v2[i+1] || x1[v2[i+1]]==v2[i]){
                cnt++;
        }
    }
    ll ans1=0,ans2=0,ans3=0;
    sort(cst,cst+m);
    for(int i=0;i<cnt;i++){
        ans+=(cst[i]*2);
    }
    int re=v1.size()+v2.size()-cnt*2-2;
    for(int j=1,i=cnt;j<=re;j++,i++){
        ans1+=cst[i];
    }
    int re2=v1.size()+v3.size()-cnt*2-2;
    for(int j=0,i=cnt;j<=re2;j++,i++){

    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        g[i].clear();
        cost[i].clear();
    }
    v1.clear();
    v2.clear();
    memset(cst,0,sizeof(cst));
    memset(path,0,sizeof(path));
    memset(x1,0,sizeof(x1));
    }
    return 0;
}
