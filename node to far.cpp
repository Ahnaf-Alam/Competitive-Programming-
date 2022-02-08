#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v [10001];
map<ll,ll> level,vis;
void bfs(int s,int ttl){
    queue<int> q;
    q.push(s);
    level[s]=0;
    vis[s]=1;
    while(q.size()>0){
        int tmp=q.front();
        q.pop();
        if(level[tmp]>ttl) break;
        for(int i=0;i<v[tmp].size();i++){
            if(vis[v[tmp][i]]==0){
                level[v[tmp][i]]=level[tmp]+1;
                vis[v[tmp][i]]=1;
                q.push(v[tmp][i]);
            }
        }
    }
}
int  main()
{
    int n,total=1;
    while((scanf("%d",&n))==1){
        int x,y;
        map<ll,ll>vis2;
        vector<ll> node;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            if(vis2[x]==0){
                node.push_back(x);
                vis2[x]=1;

            }
            if(vis2[y]==0){
                node.push_back(y);
                vis2[y]=1;
            }
        }
       while((scanf("%d %d",&x,&y))==2){
        int cnt=0;
        if(x==0 && y==0) break;
         bfs(x,y);
         for(int i=0;i<node.size();i++){
            //cout<<node[i]<<" ";
            if(vis[node[i]]==1 && level[node[i]]<=y)
                cnt++;
         }
         //cout<<node.size()<<endl;
         level.clear();
         vis.clear();
         //memset(level,0,sizeof(level));
         //memset(vis,0,sizeof(vis));
         //cout<<node.size()<<endl;
         printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",total++,node.size()-cnt,x,y);
       }
       //cout<<ans<<endl;
       for(int i=0;i<1000;i++) v[i].clear();
       //memset(vis2,0,sizeof(vis2));
       vis2.clear();
       node.clear();
    }
}
