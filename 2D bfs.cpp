#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int r,c;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int boomb[1001][1001];
int level[1001][1001];
int vis[1001][1001];
void bfs(int x,int y){
   queue<pii>q;
   q.push(pii(x,y));
   vis[x][y]=1;
   while(q.size()>0){
      pii top=q.front();
      q.pop();
      for(int k=0;k<4;k++){
        int tx=top.first+fx[k];
        int ty=top.second+fy[k];
        if(boomb[tx][ty]==0 && tx>=0 && tx<r && ty>=0 && ty<c && vis[tx][ty]==0){
            level[tx][ty]=level[top.first][top.second]+1;
            vis[tx][ty]=1;
            q.push(pii(tx,ty));
        }
      }
   }
}
int main()
{
    int x,y,tmp,x1,y1;
    while((scanf("%d%d",&r,&c))==2){
        if(r==0 && c==0) break;
        int b;
        scanf("%d",&b);
        for(int i=0;i<b;i++){
            scanf("%d%d",&x,&y);
            for(int j=0;j<y;j++){
                scanf("%d",&tmp);
                boomb[x][tmp]=1;
            }
        }
        scanf("%d %d",&x,&y);
        bfs(x,y);
        scanf("%d%d",&x1,&y1);
        printf("%d\n",level[x1][y1]-level[x][y]);
        memset(level,0,sizeof(level));
        memset(vis,0,sizeof(vis));
        memset(boomb,0,sizeof(boomb));
    }
}
