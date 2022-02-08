#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,m,cnt=0;
int block[21][21];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int level[1001][1001];
int vis[1001][1001];
void bfs(int x,int y){
   queue<pii>q;
   vis[x][y]=1;
   q.push(pii(x,y));
   while(q.size()>0){
    pii top=q.front();
    q.pop();
    for(int k=0;k<4;k++){
        int tx=top.first+fx[k];
        int ty=top.second+fy[k];
        if(block[tx][ty]==0 && tx>=0 && ty<n && ty>=0 && ty<m && vis[tx][ty]==0){
            cnt++;
            vis[tx][ty]=1;
            q.push(pii(tx,ty));
        }
    }
   }
}
int main()
{
    int t,test=0;
    cin>>t;
    while(t--){
         int x,y;
         char c;
         scanf("%d %d",&n,&m);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='@'){
                    x=i;
                    y=j;
                }
                if(c=='#') block[i][j]=1;
            }
         }
         bfs(x,y);
         cout<<cnt<<endl;
         //cout<<x<<" "<<y<<endl;
    }
}
