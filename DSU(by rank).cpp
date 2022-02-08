#include<bits/stdc++.h>
using namespace std;
map<int,int>par,rak;
void makeset(int n){
   par[n]=n;
   rak[n]=0;
}
int find(int x){
   if(par[x]!=x) par[x]=find(par[x]);
   return par[x];
}
void Union(int x,int y){
   int u=find(x);
   int v=find(y);

   //if(u==v) return;

   if(rak[u] > rak[v]){
        par[v]=u;
        rak[u]++;
   }
   else if(rak[u]< rak[v]){
            par[u]=v;
            rak[v]++;
   }
   else{
    par[u]=v;
    rak[v]++;
   }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) makeset(i);
    Union(1,2); cout<<max(rak[find(1)],rak[find(2)])<<endl;
    Union(2,3); cout<<max(rak[find(2)],rak[find(3)])<<endl;
    Union(3,4); cout<<max(rak[find(3)],rak[find(4)])<<endl;
    Union(5,6); cout<<max(rak[find(5)],rak[find(6)])<<endl;
    Union(6,7); cout<<max(rak[find(6)],rak[find(7)])<<endl;
    //for(int i=1;i<=n;i++) cout<<find(i)<<endl;
    //for(int i=1;i<=n;i++) cout<<rak[i]<<" ";
}
