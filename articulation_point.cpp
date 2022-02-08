#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
bool vis[100001];
int low[10001],d[100001],parent[100001],AP[10001];
void FindAP(int s){
   static int time=0;
   time++;
   low[s]=d[s]=time;
   vis[s]=true;
   int no_child=0;
   for(int i=0;i<g[s].size();i++){
    if(g[s][i]==parent[s]) continue;
    if(vis[g[s][i]]==true) low[s]=min(low[s],d[g[s][i]]);
    else{
        if(vis[g[s][i]]==false){
            parent[s]=g[s][i];
            FindAP(g[s][i]);
            low[s]=min(low[s],low[g[s][i]]);
            if(d[s]<=low[g[s][i]] && parent[s]!=0)
                AP[s]=true;
        no_child++;
        }
        if(no_child>1 && parent[s]==0) AP[s]=true;
    }
   }
}
int main()
{
    int n,e,cnt=0;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        FindAP(i);
    for(int i=1;i<=n;i++){
        if(AP[i]==true) cnt++;
    }
    cout<<cnt<<endl;
}
