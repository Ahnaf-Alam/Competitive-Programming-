#include<bits/stdc++.h>
using namespace std;
int par[10001];
void makeset(int n){
   par[n]=n;
}
int find(int x){
   if(par[x]!=x){
    par[x]=find(par[x]);
   }
   return par[x];
}
void Union(int x,int y){
   int u=find(x);
   int v=find(y);
   if(u==v) return;
   else par[u]=v;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) makeset(i);
    Union(1,2);
    Union(2,3);
    Union(4,5);
    int x,y;
    cin>>x>>y;
    if(find(x)==find(y)) cout<<"Yes\n";
    else cout<<"No\n";
    for(int i=1;i<=n;i++) cout<<par[i]<<" ";
}
