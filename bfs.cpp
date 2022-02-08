#include<bits/stdc++.h>
using namespace std;
vector<int> v [10001];
int level [10001];
bool  vis[10001];
int cnt=0;
void bfs(int s,int x){
  queue<int> q;
  q.push(s);
  level[s]=1;
  vis[s]=true;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    for(int i=0;i<v[p].size();i++){
        if(vis[p][i]==false){
            level[v[p][i]]=level[p]+1;
            if(level[v[p][i]]==x){
                cnt++;
            }
            q.push(v[p][i]);
            vis[v[p][i]]=true;
        }
    }
  }
}
int main()
{
    int n,e,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>e;
    bfs(1,e);
    cout<<cnt<<endl;
}
