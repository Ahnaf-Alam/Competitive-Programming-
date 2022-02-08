#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
bool vis[100001];
int n,e;
int low[10001],d[100001],parent[100001],AP[10001];
void bridgeutil(int s){
   static int time=0;
   time++;
   low[s]=d[s]=time;
   vis[s]=true;
   for(int i=0;i<g[s].size();i++){
        int v=g[s][i];
        if(!vis[v]){
            parent[v]=s;
            bridgeutil(v);
            low[s]=min(low[s],low[v]);
            if(low[v]>d[s])
                cout<<s<<" "<<v<<endl;
        }
        else if(v!=parent[s])
            low[s]=min(low[s],d[v]);
   }
}
void bridge(int u){
   for(int i=0;i<n;i++){
    parent[i]=0;
    vis[i]=false;
   }
   for(int i=0;i<n;i++){
    if(vis[i]==false)
        bridgeutil(i);
   }
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bridge(1);
}
