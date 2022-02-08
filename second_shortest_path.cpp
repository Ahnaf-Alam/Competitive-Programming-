
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define infinity 1<<30 //2^30
vector<int> g[10001],cost[10001];
vector<int> dis[10001];
struct node{
   int u, cost;
   node(int _u,int _cost){
      u = _u;
      cost = _cost;
   }
   bool operator < (const node& p) const { return cost> p.cost; } // operator overloading.
};
void dijkstra(int s){
  int curr;
 // for(int i=0;i<100001;i++) dis[i]=infinity;
  priority_queue<node> q;
  q.push(node(s,0));
  //dis[s]=0;

   while(q.size()>0){
     node top= q.top();
     q.pop();
     int u=top.u;
     if(dis[u].size()==0) dis[u].pb(cost[u][0]);
     else if(dis[u].back()!=cost[u][0]) dis[u].pb(cost[u][0]);
     if(dis[u].size()>2) continue;
      for(int i=0;i<g[u].size();i++){
          int v=g[u][i];
          if(dis[v].size()==2) continue;
          curr=v+cost[v][i];
          q.push(node(v,curr));
      }
   }
}
int main()
{
    int n,ed,x,y,w;
    cin>>n>>ed;
    for(int i=0;i<ed;i++){
        cin>>x>>y>>w;
        g[x].pb(y);
        g[y].pb(x);
        cost[x].pb(w);
        cost[y].pb(w);
    }
    int s;
    cin>>s;
    dijkstra(s);
    cout<<dis[n][1]<<endl;
}
