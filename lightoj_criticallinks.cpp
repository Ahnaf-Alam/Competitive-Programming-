#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
int n,e;
vector<pair<int,int>>ans;
void bridgeutil(int s,bool vis[],int d[],int low[],int parent[]){
   static int time=0;
   time++;
   low[s]=d[s]=time;
   vis[s]=true;
   for(int i=0;i<g[s].size();i++){
        int v=g[s][i];
        if(!vis[v]){
            parent[v]=s;
            bridgeutil(v,vis,d,low,parent);
            low[s]=min(low[s],low[v]);
            if(low[v]>d[s]){
                 if(s<v)
                   ans.push_back({s,v});
                 else ans.push_back({v,s});
                //cout<<s<<" "<<v<<endl;
            }
        }
        else if(v!=parent[s])
            low[s]=min(low[s],d[v]);
   }
}
void bridge(){
   int low[10001],d[100001],parent[100001],AP[10001];
    bool vis[100001];
   for(int i=0;i<n;i++){
    parent[i]=0;
    vis[i]=false;
   }
   for(int i=0;i<n;i++){
    if(vis[i]==false)
        bridgeutil(i,vis,d,low,parent);
   }
}
int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while(t--){
        //printf("\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d (%d) ",&x,&y);
           for(int j=0;j<y;j++){
              int z;
              scanf("%d",&z);
              g[x].push_back(z);
              g[z].push_back(x);
           }
        }
        bridge();
        sort(ans.begin(),ans.end());
        printf("Case %d:\n%d critical links\n",++ca,ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d - %d\n",ans[i].first,ans[i].second);
        }
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        ans.clear();
        //for(int i=0;i<ans.size();i++) ans.clear();
    }

}

